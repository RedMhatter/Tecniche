#include <stdio.h>
#define MAXN  30

int comprimi(FILE *fin, FILE *fout);
int decomprimi(FILE *fin, FILE *fout);

int main() {
    FILE *fin, *fout;
    char name_in[MAXN+1], name_out[MAXN+1], scelta;
    int i = 0;
    printf("Inserire nome del file sorgente: ");
    scanf("%s", name_in);
    printf("Inserire nome del file di output: ");
    scanf("%s", name_out);

    if(fopen(name_in, "r") == NULL)
    {
        printf("Impossibile aprire il file.");
        return 1;
    }
    else
    {
        fin = fopen(name_in, "r");
        fout = fopen(name_out, "w");
    }

    printf("Premi C per comprimere il file sorgente, D per decomprimerlo: ");
    scanf(" %c", &scelta);
    if (scelta == 'C')
        i = comprimi(fin, fout);
    else if (scelta == 'D')
        i = decomprimi(fin, fout);
    else
        printf("Scelta errata");


    fclose(fin); fclose(fout);
    return i;
}

int comprimi(FILE *fin, FILE *fout)
{
    char c0, c1;
    int counter = 0;
    int c = 0;
    fscanf(fin, "%c", &c0);
    while(1)
    {
        if(fscanf(fin, "%c", &c1) == 1)
            c++;

        if((c0 == c1 && counter < 9) && !feof(fin))
            counter++;
        else
        {
            if(counter >= 2)
                fprintf(fout, "%c$%d", c0, counter);
            else if (counter == 1)
                fprintf(fout, "%c%c", c0, c0);
            else
                fprintf(fout, "%c", c0);
            c0 = c1;
            counter = 0;
        }

        if (feof(fin))
        {
            if (c==0)
            {
                printf("File vuoto!");
                return 0;
            }
            else break;
        }
    }
    return c;
}

int decomprimi(FILE *fin, FILE *fout)
{
    char c0, c1, c2;
    int i, q;
    int c = 0;
    fscanf(fin, "%c", &c0);
    while(fscanf(fin, "%c", &c1) == 1)
    {
        c++;
        if (c1 == '$')
        {
            fscanf(fin, "%c", &c2);
            q = (c2 - '0');
            for(i=0; i<q; i++)
                fprintf(fout, "%c", c0);
            fscanf(fin, "%c", &c0);
        }
        else
        {
            fprintf(fout, "%c", c0);
            c0 = c1;
        }
    }
    fprintf(fout, "%c", c0);
    return c;
}
