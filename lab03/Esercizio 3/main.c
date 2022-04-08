#include <stdio.h>
#define namein "numeri.txt"

int main() {
    FILE *fin;
    int x0, x1, x2;
    int scartati = 0, max=0, min=0;

    fin = fopen(namein, "r");
    fscanf(fin, "%d%d", &x0, &x1);
    max = x0;
    if(x1 >= max)
        max = x1;
    else
        min = x1;
    while (fscanf(fin, "%d", &x2) == 1)
    {
        if((x0 + x1) != x2 && (x0 - x1) != x2 && (x0 * x1) != x2 && ((x1 != 0 && (x0 / (float)x1) != (float)x2) || x1 == 0))
            scartati++;
        else
        {
            if(x2>max)
                max = x2;
            else if(x2<min)
                min = x2;
            x0 = x1;
            x1 = x2;
        }
    }
    printf("Numero massimo: %d\nNumero minimo: %d\nNumeri scartati: %d", max, min, scartati);
    return 0;
}
