#include <stdio.h>
#include <stdlib.h>

struct Pixel {
    unsigned char r, g, b;
};

// загрузка BMP
struct Pixel** readBMP(const char* filename, unsigned int* width, unsigned int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Не удалось открыть файл %s\n", filename);
        return NULL;
    }

    // BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    *width = *(unsigned int*)&header[18];
    *height = *(unsigned int*)&header[22];

    // Память под картинку
    struct Pixel** image = (struct Pixel**)malloc(*height * sizeof(struct Pixel*));
    for (unsigned int i = 0; i < *height; i++) {
        image[i] = (struct Pixel*)malloc(*width * sizeof(struct Pixel));
    }

    // сама картинка
    unsigned int padding = (*width * 3) % 4;
    if (padding != 0) {
        padding = 4 - padding;
    }
    for (unsigned int y = 0; y < *height; y++) {
        for (unsigned int x = 0; x < *width; x++) {
            fread(&image[*height - 1 - y][x], sizeof(struct Pixel), 1, file);
        }
        fseek(file, padding, SEEK_CUR);
    }

    fclose(file);
    return image;
}

// дамп в файл
void writeBMP(const char* filename, unsigned int width, unsigned int height, struct Pixel** image) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Не удалось создать файл %s\n", filename);
        return;
    }

    // Заголовок BMP файла
    unsigned char header[54] = {
            0x42, 0x4D,             // Буквы 'BM' (тип файла)
            0, 0, 0, 0,             // Размер файла (пока неизвестен)
            0, 0,                   // Зарезервированные байты
            0, 0,                   // Зарезервированные байты
            54, 0, 0, 0,            // Смещение данных пикселей в файле
            40, 0, 0, 0,            // Размер заголовка BITMAPINFOHEADER
            width & 0xFF, width >> 8 & 0xFF, width >> 16 & 0xFF, width >> 24 & 0xFF, // Ширина изображения
            height & 0xFF, height >> 8 & 0xFF, height >> 16 & 0xFF, height >> 24 & 0xFF, // Высота изображения
            1, 0,                   // Количество цветовых плоскостей (1)
            24, 0,                  // Битов на пиксель (24 бита)
            0, 0, 0, 0,             // Тип сжатия (нет сжатия)
            0, 0, 0, 0,             // Размер данных изображения (пока неизвестен)
            0, 0, 0, 0,             // Горизонтальное разрешение пикселей в метрах (пока неизвестно)
            0, 0, 0, 0,             // Вертикальное разрешение пикселей в метрах (пока неизвестно)
            0, 0, 0, 0,             // Количество цветов в палитре (пока не используется)
            0, 0, 0, 0              // Количество важных цветов (пока не используется)
    };

    // размер пикселей
    unsigned int padding = (width * 3) % 4;
    if (padding != 0) {
        padding = 4 - padding;
    }
    unsigned int dataSize = (width * 3 + padding) * height;

    // обновление заголовка
    *(unsigned int*)&header[2] = 54 + dataSize;
    *(unsigned int*)&header[34] = dataSize;

    // запись заголовка
    fwrite(header, sizeof(unsigned char), 54, file);

    // пищем картинку
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            fwrite(&image[height - 1 - y][x], sizeof(struct Pixel), 1, file);
        }
        unsigned char pad = 0;
        for (unsigned int p = 0; p < padding; p++) {
            fwrite(&pad, sizeof(unsigned char), 1, file);
        }
    }

    fclose(file);
}

// Линейная фильрация: blur, размытие
void applyLinearFilter(unsigned int width, unsigned int height, struct Pixel** image) {
    // Копия картинки в памяти
    struct Pixel** filtered_image = (struct Pixel**)malloc(height * sizeof(struct Pixel*));
    for (unsigned int i = 0; i < height; i++) {
        filtered_image[i] = (struct Pixel*)malloc(width * sizeof(struct Pixel));
    }

    // Сама фильтрация
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            // Усреднение как критериальная функция
            unsigned int sum_r = 0, sum_g = 0, sum_b = 0;
            unsigned int count = 0;
            for (int dy = -1; dy <= 1; dy++) {
                for (int dx = -1; dx <= 1; dx++) {
                    int nx = x + dx;
                    int ny = y + dy;
                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        sum_r += image[ny][nx].r;
                        sum_g += image[ny][nx].g;
                        sum_b += image[ny][nx].b;
                        count++;
                    }
                }
            }
            // Усредняем и пишем в отфильтрованное изображение
            filtered_image[y][x].r = sum_r / count;
            filtered_image[y][x].g = sum_g / count;
            filtered_image[y][x].b = sum_b / count;
        }
    }

    // отфильтрованное -> исходное
    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {
            image[i][j] = filtered_image[i][j];
        }
    }

    // Чистим память: отфильтрованное изображение уже не нужно
    for (unsigned int i = 0; i < height; i++) {
        free(filtered_image[i]);
    }
    free(filtered_image);
}

int main() {
    unsigned int width, height;
    struct Pixel** image = readBMP("input.bmp", &width, &height);
    if (!image) {
        return 1;
    }

    applyLinearFilter(width, height, image);
    writeBMP("output.bmp", width, height, image);

    // Освобождаем память
    for (unsigned int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}
