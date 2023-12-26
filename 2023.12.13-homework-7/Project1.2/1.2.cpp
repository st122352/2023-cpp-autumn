#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FILE* inf = fopen("in.txt", "r");

    if (inf == NULL) 
    {
        printf("AGHTUNG ERROR");
        return 1;
    }

    int maxLength = 0;
    char longestSentence[1000];
    char currentSentence[1000];

    while (fgets(currentSentence, sizeof(currentSentence), inf)) 
    {
        int length = 0;
        for (int i = 0; currentSentence[i] != '\0'; i++) 
        {
            if (currentSentence[i] != '\n') 
            {
                length++;
            }
        }

        if (length > maxLength)
        {
            maxLength = length;
            strcpy(longestSentence, currentSentence);
        }
    }

    fclose(inf);

    FILE* outf = fopen("out.txt", "w");

    if (outf == NULL) 
    {
        printf("AGHTUNG ERROR_2");
        return 1;
    }

    fprintf(outf, "%s", longestSentence);

    fclose(outf);

    return 0;
}

char* strcpy(char* to, char* from)
{
   while (*from != '\0') *(to++) = *(from++);

   return from;
}
