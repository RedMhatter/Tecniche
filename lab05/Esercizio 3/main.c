#include <stdio.h>
#include <string.h>
#define MAXM 30
#define MAXL 20

void readMatrix(FILE *fin, int nr, int nc, int matrix[MAXM][MAXM]);
void printMatrix(int nr, int nc, int matrix[MAXM][MAXM]);
int rotateMatrix(int nr, int nc, int matrix[MAXM][MAXM]);

typedef struct x
{
   char selettore[MAXL];
   int indice;
   char direzione[MAXL];
   int posizioni;
} s;

int main() {
    FILE *fin;
    char nameFile[MAXL];
    int matrix[MAXM][MAXM], nr, nc;
    printf("Inserisci il nome del file: ");
    scanf("%s", nameFile);

    fin = fopen(nameFile, "r");
    fscanf(fin, "%d%d", &nr, &nc);
    readMatrix(fin, nr, nc, matrix);
    fclose(fin);

    printMatrix(nr, nc, matrix);
    while(rotateMatrix(nr, nc, matrix) == 0)
        printMatrix(nr, nc, matrix);

    return 0;
}

void readMatrix(FILE *fin, int nr, int nc, int matrix[MAXM][MAXM])
{
    int i, j;
    for (i=0; i<nr; i++)
        for (j=0; j<nc; j++)
            fscanf(fin, "%d", &matrix[i][j]);
}

void printMatrix(int nr, int nc, int matrix[MAXM][MAXM])
{
    int i, j;
    for (i=0; i<nr; i++)
    {
        for (j=0; j<nc; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

int rotateMatrix(int nr, int nc, int matrix[MAXM][MAXM])
{
    char temp[100];
    int vr[MAXM];
    int i;
    s rule;
    printf("Inserisci una stringa nella forma\n\t<selettore> <indice> <direzione> <posizioni>:\n");
    scanf("%s%d%s%d", rule.selettore, &rule.indice, rule.direzione, &rule.posizioni);
    rule.indice = rule.indice - 1;

    if(strcmp(rule.selettore, "fine") != 0)
    {
        if(strcmp(rule.selettore, "riga") == 0 && (rule.indice>=0 && rule.indice<nr))
        {
            rule.posizioni = rule.posizioni % nc;
            if(strcmp(rule.direzione, "destra") == 0)
            {
                for (i=0; i<nc; i++)
                    vr[(i+rule.posizioni) % nc] = matrix[rule.indice][i];
            }
            else if (strcmp(rule.direzione, "sinistra") == 0)
            {
                for (i=0; i<nc; i++)
                    vr[(i+nc-rule.posizioni) % nc] = matrix[rule.indice][i];
            }
            else
            {
                printf("Risposta non valida\n");
                return 0;
            }

            for (i=0; i<nc; i++)
                matrix[rule.indice][i] = vr[i];
        }

        else if(strcmp(rule.selettore, "colonna") == 0 && (rule.indice>=0 && rule.indice<nc))
        {
            rule.posizioni = rule.posizioni % nr;
            if(strcmp(rule.direzione, "giu") == 0)
            {
                for (i=0; i<nr; i++)
                    vr[(i+rule.posizioni) % nr] = matrix[i][rule.indice];
            }
            else if (strcmp(rule.direzione, "su") == 0)
            {
                for (i=0; i<nr; i++)
                    vr[(i+nr-rule.posizioni) % nr] = matrix[i][rule.indice];
            }
            else
            {
                printf("Risposta non valida\n");
                return 0;
            }

            for (i=0; i<nr; i++)
                matrix[i][rule.indice] = vr[i];
        }
        else
            printf("Risposta non valida\n");

        return 0;
    }
    else
        return 1;
}