#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int strcmp(char* str1, char* str2)
{
	while (*str1 && (*str1 == *str2))
	{
		str1++;
		str2++;
	}

	if (*(char*)str1 - *(char*)str2 == 0)
	{
		printf("SUCCESS");
		return 0;
	}

	if (*(char*)str1 - *(char*)str2 > 0)
	{
		printf("FAIL_2");
		return 1;
	}

	if (*(char*)str1 - *(char*)str2 < 0)
	{
		printf("FAIL_1");
		return -1;
	}

	return EXIT_SUCCESS;
}

int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[255] = "";

	char b[255] = "";

	fscanf(f, "%s %s\n", &a, &b);

	fclose(f);

	f = fopen("out.txt", "w");

	fprintf(f, "%d\n", strcmp(a, b));

	fclose(f);

	return EXIT_SUCCESS;
}