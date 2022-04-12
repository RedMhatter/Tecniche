#include <stdio.h>
#include <string.h>
#define MAXL 200+1

typedef struct d
{
    char index1[MAXL];
    char index2[MAXL];
} dizionario;


int main() {
    FILE *fin, *dictionary, *fout;
    char word[MAXL], dot;
    dizionario D[MAXL];
    int i, j = 0;
    int nr, found = 0;

    fin = fopen("sorgente.txt", "r");
    dictionary = fopen("dizionario.txt", "r");

    if(fin == NULL || dictionary == NULL)
        return 1;
    else
        fout = fopen("ricodificato.txt","w");


    fscanf(dictionary, "%d", &nr);
    for (i=0; i<nr; i++)
        fscanf(dictionary, "%s%s", D[i].index1, D[i].index2);
    fclose(dictionary);

    while(fscanf(fin, "%s%c", word, &dot) >= 1)
    {
        for (i=0; i<nr && found == 0; i++)
        {
            if(strstr(word, D[i].index2) != NULL)
            {
                fprintf(fout, "%s%c", D[i].index1, dot);
                found = 1;
            }
            /*else
                //fprintf(fout, "%")*/
        }

        found = 0;
    }
    return 0;
}
