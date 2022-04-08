#include <stdio.h>
#define MAXN 20

void readMatrix(int matrix[MAXN][MAXN], int nr, int nc, FILE *fin);
void printMatrix(int matrix[MAXN][MAXN], int nr, int nc);
void square_max(int matrix[MAXN][MAXN], int nr, int nc, int dim);

int main() {
    char namein[MAXN+1];
    int matrix[MAXN][MAXN];
    int nr, nc, dim, min;
    FILE *fin;

    printf("Inserisci il nome del file: ");
    scanf("%s", namein);
    if(fopen(namein, "r") == NULL)
    {
        printf("Impossibile aprire il file!");
        return 1;
    }
    else
        fin = fopen(namein, "r");

    fscanf(fin, "%d%d", &nr, &nc);
    readMatrix(matrix, nr, nc, fin);

    min = nc < nr ? nc : nr;
    do {
        printf("Inserisci un valore compreso tra 1 e %d: ", min);
        scanf("%d", &dim);
        if(dim >= 1 && dim <= min)
            square_max(matrix, nr, nc, dim);
    } while(dim >= 1 && dim <= min);

    return 0;
}

void readMatrix(int matrix[MAXN][MAXN], int nr, int nc, FILE *fin)
{
    int i, j;
    for(i=0; i<nr; i++)
        for(j=0; j<nc; j++)
            fscanf(fin, "%d", &matrix[i][j]);
}

void printMatrix(int matrix[MAXN][MAXN], int nr, int nc)
{
    int i, j;
    for(i=0; i<nr; i++)
    {
        for(j=0; j<nc; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf(("\n"));
    }
}

void square_max(int matrix[MAXN][MAXN], int nr, int nc, int dim)
{
    int i, j, r, c;
    int submatrix0[MAXN][MAXN], sum0 = 0;
    int submatrix1[MAXN][MAXN], sum1 = 0;

    printf("Le sottomatrici quadrate di dimensioni %d sono:\n\n", dim);
    for(i=0; i<=nr-dim; i++)
        for(j=0; j<=nc-dim; j++)
        {
            for (r=0; r<dim; r++)
            {
                for (c=0; c<dim; c++)
                {
                    printf("%d ", matrix[i+r][j+c]);
                    sum1 += matrix[i+r][j+c];
                    submatrix1[r][c] = matrix[i+r][j+c];
                }
                printf("\n");
            }
            if(sum1 > sum0)
            {
                for (r=0; r<dim; r++)
                    for (c=0; c<dim; c++)
                        submatrix0[r][c] = submatrix1[r][c];
                sum0 = sum1;
            }
            printf("\n");
            sum1 = 0;
        }
    printf("La sottomatrice con somma degli elementi massima (%d) e': \n\n", sum0);
    printMatrix(submatrix0, dim, dim);
}