#include <stdio.h>
#define MAXN 50

void readMatrix(int map[][MAXN], int nr, int nc, FILE *fin);
void search(int map[][MAXN], int nr, int nc);

typedef struct{
    int base;
    int altezza;
    int area;
    int sx[2];
} coordinate;

int main() {
    FILE *fin;
    int map[MAXN][MAXN];
    int nc, nr;

    if((fin = fopen("mappa.txt", "r")) == NULL)
        return 1;

    fscanf(fin, "%d%d", &nr, &nc);
    readMatrix(map, nr, nc, fin);
    fclose(fin);

    search(map, nr, nc);
    return 0;
}

void readMatrix(int map[][MAXN], int nr, int nc, FILE *fin)
{
    int i, j;

    for (i=0; i<nr; i++)
        for (j=0; j<nc; j++)
            fscanf(fin, "%d", &map[i][j]);
}

void search(int map[][MAXN], int nr, int nc)
{
    int i, j, k, m;
    int altezza, base, area;
    int altezzaMAX=0, baseMAX=0, areaMAX=0;
    coordinate h, b, A;

    for (i=0; i<nr; i++)
    {
        for (j=0; j<nc; j++)
        {
            if (map[i][j] == 1)
            {
                for (k=0, base=0; k<nc-j && map[i][j+k] == 1; k++)
                        base++;

                for (k=0, altezza=0; k<nr-i && map[i+k][j] == 1; k++)
                        altezza++;

                area = base * altezza;
                if(baseMAX < base)
                {
                    baseMAX = base;
                    b.base = base, b.altezza = altezza, b.area = area;
                    b.sx[0] = i, b.sx[1] = j;
                }
                if(altezzaMAX < altezza)
                {
                    altezzaMAX = altezza;
                    h.base = base, h.altezza = altezza, h.area = area;
                    h.sx[0] = i, h.sx[1] = j;
                }
                if(areaMAX < area)
                {
                    areaMAX = area;
                    A.base = base, A.altezza = altezza, A.area = area;
                    A.sx[0] = i, A.sx[1] = j;
                }

                for (k=0; k<altezza; k++)
                    for (m=0; m<base; m++)
                        map[i+k][j+m] = 0;
            }
        }
    }

    printf("Max Base: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", b.sx[0], b.sx[1], b.base, b.altezza, b.area);
    printf("Max Area: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", A.sx[0], A.sx[1], A.base, A.altezza, A.area);
    printf("Max Altezza: estr. sup. SX=<%d,%d> b=%d, h=%d, Area=%d\n", h.sx[0], h.sx[1], h.base, h.altezza, h.area);
}