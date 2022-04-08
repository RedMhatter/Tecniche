#include <stdio.h>

int main()
{
    char operazione;
    float a, b;

    printf("Inserire l'operazione desiderata (+, -, *, /): ");
    operazione = getchar();
    printf("Inserire i due operandi: ");
    scanf("%f%f", &a, &b);

    switch (operazione) {
        case '+':
            printf("+ %.2f", a+b);
            break;
        case '-':
            printf("- %.2f", a-b);
            break;
        case '*':
            printf("* %.2f", a*b);
            break;
        case '/':
            if (b!=0)
                printf("/ %.2f", a/b);
            else
                printf("Errore! Divisione per 0!");
            break;
    }
    return 0;
}
