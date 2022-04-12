#include <stdio.h>
#define MAXN 20
void zeroArray(int v[]);

int main() {
    FILE *fin;
    int i, j;
    int nr, nc, matrix[MAXN][MAXN], punti[MAXN];
    int max = 0, index_max = 0;
    if((fin = fopen("mat.txt", "r")) == NULL)
        return 1;

    fscanf(fin, "%d%d", &nr, &nc);
    zeroArray(punti);
    for(i=0; i<nr; i++)
        for(j=0; j<nc; j++)
            fscanf(fin, "%d", &matrix[i][j]);

    for(j=0; j<nc; j++)
    {
        for(i=0; i<nr; i++)
        {
            punti[i] += matrix[i][j];
            if (punti[i] > max)
            {
                max = punti[i];
                index_max = i;
            }
        }
        printf("Giornata %d, capolista squadra: %d\n", j+1, index_max);
        index_max = 0;
        max = 0;
    }
    return 0;
}

void zeroArray(int v[])
{
    int i;
    for(i=0; i<MAXN; i++)
        v[i] = 0;
}