#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* strmult(const char* str, int n) 
{
    int len = strlen(str); 

    int result_len = len * n; 

    char* result = (char*)malloc(result_len + 1); 

    for (int i = 0; i < n; i++) 
    {
        strncpy(result + (i * len), str, len); 
    }

    result[result_len] = '\0';

    return result;
}

int main() 
{
    FILE* f = fopen("in.txt", "r");

    const char* str = "";

    int mult = 0;

    fscanf(f, "%s %s\n", &str, &mult);

    fclose(f);

    char* result = strmult(str, mult);

    f = fopen("out.txt", "w");

    printf("Результат: %s\n", result);

    fclose(f); 

    return 0;
}