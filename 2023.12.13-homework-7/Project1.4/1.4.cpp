#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char* strstr(const char* str1, const char* str2)
{
    if (!*str2) 
    {
        return (char*)str1;
    }
    while (*str1) 
    { 
        const char* h = str1;

        const char* n = str2;

        while (*str1 && *n && *str1 == *n) 
        {
            str1++;
            n++;
        }
        if (!*n) 
        {
            return (char*)h;
        }
        str1 = h + 1; 
    }

    return NULL; 
}

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[255] = "";

	char b[255] = "";

	fscanf(f, "%s %s\n", &a, &b);

	fclose(f);

	f = fopen("out.txt", "w");

	fprintf(f, "%s\n", strstr(a, b));

	fclose(f);

	printf("SUCCESS");

	return EXIT_SUCCESS;
}
