#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


char* strcat(char* str1, const char* str2)
{

	char* begin = str1;

	while (*str1)
	{
		str1++;
	}

	while (*str1++ = *str2++);
	{
		*str1 = '\0';
	}

	return begin;

}

int strLen(char* str)
{
	int res = 0;

	while (str[++res] != '\0');

	return res;
}


int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[255] = "";
	char b[255] = "";

	fscanf(f, "%s %s\n", &a, &b);

	fclose(f);

	strcat(a, b);

	f = fopen("out.txt", "w");

	fprintf(f, "%s\n", a);

	fclose(f);

	printf("SUCCESS");

	return EXIT_SUCCESS;
}