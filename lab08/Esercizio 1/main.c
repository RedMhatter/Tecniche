#include <stdio.h>
#include <stdbool.h>
#define MAXN 50

int leggiMatrice(int map[][MAXN], int *nr, int *nc);
bool riconosciRegione(int map[][MAXN],int nr,int nc,int r,int c,int *b,int *h);

typedef struct{
    int base;
    int altezza;
    int area;
    int sx[2];
} coordinate;

int main() {
    int map[MAXN][MAXN];
    int nc, nr, r, c, b=0, h=0, A;
    int altezzaMAX=0, baseMAX=0, areaMAX=0;
    coordinate base, altezza, area;

    leggiMatrice(map, &nr, &nc);

    for(r=0; r<nr; r++)
    {
        for(c=0; c<nc; c++)
            if(riconosciRegione(map, nr, nc, r, c, &b, &h))
            {
                A = b*h;
                if(baseMAX < b)
                {
                    baseMAX = b;
                    base.base = b, base.altezza = h, base.area = A;
                    base.sx[0] = r, base.sx[1] = c;
                }
                if(altezzaMAX < h)
                {
                    altezzaMAX = h;
                    altezza.base = b, altezza.altezza = h, altezza.area = A;
                    altezza.sx[0] = r, altezza.sx[1] = c;
                }
                if(areaMAX < A)
                {
                    areaMAX = A;
                    area.base = b, area.altezza = h, area.area = A;
                    area.sx[0] = r, area.sx[1] = c;
                }
            }
    }

    printf("Max Base: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", base.sx[0], base.sx[1], base.base, base.altezza, base.area);
    printf("Max Area: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", area.sx[0], area.sx[1], area.base, area.altezza, area.area);
    printf("Max Altezza: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", altezza.sx[0], altezza.sx[1], altezza.base, altezza.altezza, altezza.area);

    return 0;
}

int leggiMatrice(int map[][MAXN], int *nr, int *nc)
{
    FILE *fin;
    int i, j;

    if((fin = fopen("mappa.txt", "r")) == NULL)
        return 1;

    fscanf(fin, "%d%d", nr, nc);

    for (i=0; i<*nr; i++)
        for (j=0; j<*nc; j++)
            fscanf(fin, "%d", &map[i][j]);

    fclose(fin);
}

bool riconosciRegione(int map[][MAXN],int nr, int nc, int r, int c, int *b, int *h)
{
    *b = *h = 0;
    int k, m;
    if (map[r][c] == 0)
        return false;

    if (map[r][c] == 1)
    {
        for (k=0, *b=0; k<nc-c && map[r][c+k] == 1; k++)
            (*b)++;

        for (k=0, *h=0; k<nr-r && map[r+k][c] == 1; k++)
            (*h)++;

        for (k=0; k<*h; k++)
            for (m=0; m<*b; m++)
                map[r+k][c+m] = 0;
    }
    return true;
}