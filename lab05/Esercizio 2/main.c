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
    char word[MAXL], temp[MAXL], dot;
    dizionario D[MAXL];
    int i, index_word = 0;
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
        for (i=0; i<nr && found == 0; i++)
            if(strstr(word, D[i].index2) != NULL)
            {
                index_word = i;
                found = 1;
            }

        if (found == 0)
            fprintf(fout, "%s", word, dot);
        else
        {
            if(strlen(word) - strlen(D[index_word].index2) > 0)
            {
                for (i=0; i < strlen(word); i++)
                {
                    strncpy(temp, word+i, strlen(D[index_word].index2));
                    printf("%s %d", temp, strlen(word));

                    if(strcmp(temp, D[index_word].index2) != 0)
                        fprintf(fout, "%c", word[i]);
                    else
                    {
                        fprintf(fout, "%s", D[index_word].index1);
                        i += strlen(D[index_word].index2) - 1;
                    }

                    memset(temp,0,strlen(temp)); //Devo cercare di cambiare questo comando
                }
            }
            else
                fprintf(fout, "%s", D[index_word].index1);
        }
        found = 0;
        fprintf(fout, "%c", dot);
        index_word = 0;
    }
    fclose(fin), fclose(fout);
    return 0;
}
