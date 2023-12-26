#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int countWords(int words)
{
	FILE* infile = fopen("in.txt", "r");

	if (infile == NULL)
	{
		printf("AGHTUNG ERROR");
		return 1;
	}

	char c;

	while ((c = fgetc(infile)) != EOF)
	{
		if (c == ' ' || c == '\n')
		{
			words++;
		}
	}

	fclose(infile);

	FILE* outfile = fopen("out.txt", "w");


	if (infile == NULL)
	{
		printf("AGHTUNG ERROR_2");
		return 1;
	}

	fprintf(outfile, "%d", words);

	fclose(outfile);

	return 0;
}

int main(int argc, char** argv)
{
	countWords(0);

    return 0;
}
