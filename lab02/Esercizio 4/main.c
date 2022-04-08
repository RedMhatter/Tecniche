#include <stdio.h>
#define MAXN  30

int codifica(FILE *fin, FILE *fout);
int decodifica(FILE *fin, FILE *fout);

int main() {
    FILE *fin, *fout;
    char name_in[MAXN], name_out[MAXN], scelta;
    int r;

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

    printf("Premi C per codificare il file sorgente, D per decodificarlo: ");
    scanf(" %c", &scelta);

    switch (scelta) {
        case 'C':
            r = codifica(fin, fout);
            if(r != 0)
                printf("Codifica riuscita!");
            break;
        case 'D':
            r = decodifica(fin, fout);
            if(r != 0)
                printf("Decodifica riuscita!");
            break;
        default:
            printf("Scelta errata!");
            return 1;
    }
    fclose(fin), fclose(fout);
    return r;
}

//Funzione di codifica
int codifica(FILE *fin, FILE *fout)
{
    char c1, c0 = -1;
    int k=0, h=0, counter=0;

    while(fscanf(fin, "%c", &c1) == 1)
    {
        if (c1 >= '0' && c1 <= '9')
        {
            c0 = c1;
            c1 = (c1 - '0' + k) % 10 + '0';
            k++;
        }
        if(c0 != -1)
        {
            if(c0 >= 'A' && c0 <= 'Z')
                h = c0 - 'A';
            else if (c0 >= 'a' && c0 <= 'z')
                h = c0 - 'a';

            if(c1 >= 'A' && c1 <= 'Z')
                c1 = (c1 - 'A' + h) % 26 + 'A';
            else if (c1 >= 'a' && c1 <= 'z')
                c1 = (c1 - 'a' + h) % 26 + 'a';
        }
        c0 = c1;
        h = 0;
        counter++;
        fprintf(fout, "%c", c1);
    }
    if (counter == 0)
    {
        printf("Errore. File vuoto.");
        return 0;
    }
    return counter;
}

//Funzione di decodifica
int decodifica(FILE *fin, FILE *fout)
{
    char c1, c0 = -1;
    int k=0, h=0, counter=0;

    while(fscanf(fin, "%c", &c1) == 1)
    {
        if (c1 >= '0' && c1 <= '9')
        {
            c0 = c1;
            if ((c1 - '0' + k) < 0)
                c1 = (c1 - '0' + k + 10) % 10 + '0';
            else
                c1 = (c1 - '0' + k) % 10 + '0';
            k--;
        }
        if(c0 != -1)
        {
            if(c0 >= 'A' && c0 <= 'Z')
                h = c0 - 'A';
            else if (c0 >= 'a' && c0 <= 'z')
                h = c0 - 'a';

            c0 = c1;

            if(c1 >= 'A' && c1 <= 'Z')
            {
                if ((c1 - 'A' - h) < 0)
                    c1 = (c1 - 'A' - h + 26) % 26 + 'A';
                else
                    c1 = (c1 - 'A' - h) % 26 + 'A';
            }
            else if (c1 >= 'a' && c1 <= 'z')
            {
                if ((c1 - 'a' - h) < 0)
                    c1 = (c1 - 'a' - h + 26) % 26 + 'a';
                else
                    c1 = (c1 - 'a' - h) % 26 + 'a';
            }
        }
        else if (c0 == -1)
            c0 = c1;
        fprintf(fout, "%c", c1);
        h = 0;
        counter++;
    }
    if (counter == 0)
    {
        printf("Errore. File vuoto.");
        return 0;
    }
    return counter;
}