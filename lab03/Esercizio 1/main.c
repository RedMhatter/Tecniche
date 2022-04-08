#include <stdio.h>
#define filein "input.txt"
#define fileout "testo.txt"

int main() {
    FILE *fin, *fout;
    int c=0, real_count = 0, i, space = 0;
    char c0, c1;

    if (fopen(filein, "r") == NULL)
    {
        printf("Impossibile aprire il file");
        return 1;
    }
    else
    {
        fin = fopen(filein, "r");
        fout = fopen(fileout, "w");
    }

    while(fscanf(fin, "%c", &c0) == 1)
    {
        real_count++;
        //Conta dei caratteri
        if(c0 != '\n')
            c++;
        //Sostituisce le cifre
        if (c0 >= '0' && c0 <= '9')
            fprintf(fout, "*");
        //Punteggiatura
        else if (c0 == '.' || c0 == ',' || c0 == ';' || c0 == ':' || c0 == '!' || c0 == '?') {
            fprintf(fout, "%c", c0);
            while(fscanf(fin, "%c", &c1) == 1 && c1 == ' ' || c1 == '\n')
            {
                real_count++;
                if (c1 != '\n') {
                    fprintf(fout, "%c", c1);
                    c++;
                } else if (c1 == '\n') {
                    for (i = c; i < 25; i++)
                        fprintf(fout, " ");
                    fprintf(fout, "| c:%d \n", real_count);
                    real_count = 0;
                    c = 0;
                }
                if(c == 25)
                {
                    fprintf(fout, "| c:%d \n", real_count);
                    c = 0;
                    real_count = 0;
                }
                space++;
            }

            if (space==0){
                fprintf(fout, " ");
                c++;
            }
            else
                space = 0;
            if(!feof(fin))
            {
                if (c1 >= 'a' && c1 <= 'z' && (c0 == '.' || c0 == '!' || c0 == '?'))
                    fprintf(fout, "%c", (c1 - 32));
                else
                    fprintf(fout, "%c", c1);
                c++;
                real_count++;
            }
        }
        else if (c0 != '\n')
            fprintf(fout, "%c", c0);

        if(c == 25)
        {
            fprintf(fout, "| c:%d \n", real_count);
            c = 0;
            real_count = 0;
        }
        else if (c0 == '\n')
        {
            for(i=c; i<25; i++)
                fprintf(fout, " ");
            fprintf(fout, "| c:%d \n", real_count);
            c = 0;
            real_count = 0;
        }
    }
    if (c>0)
    {
        for(i=c; i<25; i++)
            fprintf(fout, " ");
        fprintf(fout, "| c:%d", real_count);
    }

    fclose(fin), fclose(fout);
    return 0;
}