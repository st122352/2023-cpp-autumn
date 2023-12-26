#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

char* substr(char* str, int from, int to)
{
	for (int i = 0; i <= to - 1; i++)
	{
		str[i] = str[from + i];
	}

	str[to] = NULL;

	return str;
}
	
int main(int argc, char* argv[])
{
	FILE* f = fopen("in.txt", "r");

	char a[255] = "";

	int b = 0;

	int c = 0;

	fscanf(f, "%s %d %d\n", &a, &b, &c);

	fclose(f);

	f = fopen("out.txt", "w");

	fprintf(f, "%s\n", substr(a, b, c));

	fclose(f);

	return EXIT_SUCCESS;
}