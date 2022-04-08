#include <stdio.h>

int main()
{
    FILE *fin, *fout;
    if (fopen("Operations.txt", "r") != NULL)
        fin = fopen("Operations.txt", "r");
    else
    {
        printf("Impossibile aprire il file.");
        return 1;
    }

    fout = fopen("Results.txt", "w");

    char operazione;
    float a, b;

    while(!feof(fin))
    {
        if (!feof(fin))
        {
            operazione = fgetc(fin);
            fscanf(fin,"%f%f ", &a, &b);

            switch (operazione) {
                case '+':
                    fprintf(fout,"+ %.2f\n", a+b);
                    break;
                case '-':
                    fprintf(fout,"- %.2f\n", a-b);
                    break;
                case '*':
                    fprintf(fout,"* %.2f\n", a*b);
                    break;
                case '/':
                    if (b!=0)
                        fprintf(fout,"/ %.2f\n", a/b);
                    else
                        fprintf(fout, "Errore! Divisione per 0!\n");
                    break;
            }
        }
    }
    return 0;
}
