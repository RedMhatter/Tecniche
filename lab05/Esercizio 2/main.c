#include <stdio.h>
#include <string.h>
#define MAXL 200+1
typedef struct d
{
    char index1[MAXL];
    char index2[MAXL];
} dizionario;

int isSubstring(char word[], char D[], int end);

int main() {
    FILE *fin, *dictionary, *fout;
    char word[MAXL], dot;
    dizionario D[MAXL];
    int i, j, end, start;
    int nr, found = 0;

    //Apertura file
    fin = fopen("sorgente.txt", "r");
    dictionary = fopen("dizionario.txt", "r");

    if(fin == NULL || dictionary == NULL)
        return 1;
    else
        fout = fopen("ricodificato.txt","w");

    //Dictionary
    fscanf(dictionary, "%d", &nr);
    for (i=0; i<nr; i++)
        fscanf(dictionary, "%s%s", D[i].index1, D[i].index2);
    fclose(dictionary);

    //Algoritmo
    while(fscanf(fin, "%s%c", word, &dot) >= 1)
    {
        for (i=0; i < nr && found == 0; i++)
        {
            end = strlen(word) - strlen(D[i].index2);
            if(end>=0)
                if((start = isSubstring(word, D[i].index2, end)) != -1)
                {
                    //Stampa della parola
                    for (j=0; j< strlen(word); j++)
                    {
                        if (j == start)
                        {
                            fprintf(fout, "%s", D[i].index1);
                            j += strlen(D[i].index2) - 1;
                        }
                        else
                            fprintf(fout, "%c", word[j]);
                    }
                    found = 1;
                }
        }

        if(!found)
            fprintf(fout, "%s%c", word, dot);
        else if (dot != -1)
            fprintf(fout, "%c", dot);

        dot = -1;
        found = 0;

    }
    fclose(fin), fclose(fout);
    return 0;
}

int isSubstring(char word[], char D[], int end)
{
    int i, j, found;

    for (i=0; i <= end; i++)
    {
        found = 1;
        for(j=0; j< strlen(D); j++)
            if(word[i+j] != D[j])
                found = 0;

        if(found == 1)
            return i;
    }
    return -1;
}