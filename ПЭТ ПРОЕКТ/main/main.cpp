#include <stdio.h>
#include <stdlib.h>

struct Pixel {
    unsigned char r, g, b;
};

// �������� BMP
struct Pixel** readBMP(const char* filename, unsigned int* width, unsigned int* height) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "�� ������� ������� ���� %s\n", filename);
        return NULL;
    }

    // BMP header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    *width = *(unsigned int*)&header[18];
    *height = *(unsigned int*)&header[22];

    // ������ ��� ��������
    struct Pixel** image = (struct Pixel**)malloc(*height * sizeof(struct Pixel*));
    for (unsigned int i = 0; i < *height; i++) {
        image[i] = (struct Pixel*)malloc(*width * sizeof(struct Pixel));
    }

    // ���� ��������
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

// ���� � ����
void writeBMP(const char* filename, unsigned int width, unsigned int height, struct Pixel** image) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "�� ������� ������� ���� %s\n", filename);
        return;
    }

    // ��������� BMP �����
    unsigned char header[54] = {
            0x42, 0x4D,             // ����� 'BM' (��� �����)
            0, 0, 0, 0,             // ������ ����� (���� ����������)
            0, 0,                   // ����������������� �����
            0, 0,                   // ����������������� �����
            54, 0, 0, 0,            // �������� ������ �������� � �����
            40, 0, 0, 0,            // ������ ��������� BITMAPINFOHEADER
            width & 0xFF, width >> 8 & 0xFF, width >> 16 & 0xFF, width >> 24 & 0xFF, // ������ �����������
            height & 0xFF, height >> 8 & 0xFF, height >> 16 & 0xFF, height >> 24 & 0xFF, // ������ �����������
            1, 0,                   // ���������� �������� ���������� (1)
            24, 0,                  // ����� �� ������� (24 ����)
            0, 0, 0, 0,             // ��� ������ (��� ������)
            0, 0, 0, 0,             // ������ ������ ����������� (���� ����������)
            0, 0, 0, 0,             // �������������� ���������� �������� � ������ (���� ����������)
            0, 0, 0, 0,             // ������������ ���������� �������� � ������ (���� ����������)
            0, 0, 0, 0,             // ���������� ������ � ������� (���� �� ������������)
            0, 0, 0, 0              // ���������� ������ ������ (���� �� ������������)
    };

    // ������ ��������
    unsigned int padding = (width * 3) % 4;
    if (padding != 0) {
        padding = 4 - padding;
    }
    unsigned int dataSize = (width * 3 + padding) * height;

    // ���������� ���������
    *(unsigned int*)&header[2] = 54 + dataSize;
    *(unsigned int*)&header[34] = dataSize;

    // ������ ���������
    fwrite(header, sizeof(unsigned char), 54, file);

    // ����� ��������
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

// �������� ���������: blur, ��������
void applyLinearFilter(unsigned int width, unsigned int height, struct Pixel** image) {
    // ����� �������� � ������
    struct Pixel** filtered_image = (struct Pixel**)malloc(height * sizeof(struct Pixel*));
    for (unsigned int i = 0; i < height; i++) {
        filtered_image[i] = (struct Pixel*)malloc(width * sizeof(struct Pixel));
    }

    // ���� ����������
    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            // ���������� ��� ������������� �������
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
            // ��������� � ����� � ��������������� �����������
            filtered_image[y][x].r = sum_r / count;
            filtered_image[y][x].g = sum_g / count;
            filtered_image[y][x].b = sum_b / count;
        }
    }

    // ��������������� -> ��������
    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {
            image[i][j] = filtered_image[i][j];
        }
    }

    // ������ ������: ��������������� ����������� ��� �� �����
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

    // ����������� ������
    for (unsigned int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}
