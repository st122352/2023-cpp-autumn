#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstdlib>
#include <stdio.h>


int largestsentance(int maxlen)
{
	FILE* infile = fopen("in.txt", "r");

	char longestSen[1000];
	char currentSen[1000];

	while (fgets(currentSen, sizeof(currentSen), infile))
	{
		int len = 0;

		for (int i = 0; currentSen[i] != '\0'; i++)
		{
			if (currentSen[i] != '\n')
			{
				len++;
			}
		}

		if (len > maxlen)
		{
			maxlen = len;
			strcpy(longestSen, currentSen);
		}
	}

	fclose(infile);

	FILE* outfile = fopen("out.txt", "w");

	fprintf(outfile, "%s", longestSen);

	fclose(outfile);

	return 0;
}

void strcpy(char* to, char* from)
{

	while ((*to++ = *from++) != '\0');

}

int main()
{
    
}
