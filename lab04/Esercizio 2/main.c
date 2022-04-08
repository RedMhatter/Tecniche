#include <stdio.h>
#define MAXN 30

void ruota(int v[], int N, int P, int dir);
int main() {
    int v[MAXN];
    int N = 0, i = 0, dir = 0, P = 0;

    do {
        printf("Quanti numeri vuoi inserire? (<=30): ");
        scanf("%d", &N);
        N > 30 || N < 0 ? printf("Scelta errata!\n") : printf("Inserisci %d numeri: ", N);
    } while(N > 30 || N < 0);

    //Input
    do {
        scanf("%d", &v[i]);
        i++;
    } while(i < N);

    do {
        printf("In che verso vuoi spostare il vettore? SX (1), DX (-1): ");
        scanf("%d", &dir);
        printf("Di quante posizioni vuoi spostare il vettore (P<N)? Inserisci 0 per terminare: ");
        scanf("%d", &P);
        P >= N || P < 0  || (dir != 1 && dir != -1) ? printf("Scelta errata!\n") : ruota(v, N, P, dir);
    } while(P != 0);

}

void ruota(int v[], int N, int P, int dir)
{
    int i, temp[N];
    if (P != 0)
    {
        if (dir == -1)
            for (i = 0; i < N; i++) //Ruota a dx
                temp[(i + P) % N] = v[i];
        else
            for (i = 0; i < N; i++) //Ruota a sx
                temp[(i + N-P) % N] = v[i];

        for (i = 0; i < N; i++) //Stampa
        {
            v[i] = temp[i];
            temp[i] = 0;
            printf("%d ", v[i]);
        }
        printf("\n");
    }
    else
        printf("Programma terminato.");
}