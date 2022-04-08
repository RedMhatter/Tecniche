#include <stdio.h>
#define MAXN 30

void sottoSequenze(int V[], int N);
int maximum(int V[], int N);

int main() {
    int V[MAXN];
    int n = 0, top = 0;

    do {
        printf("Quanti numeri vuoi inserire? (<=30): ");
        scanf("%d", &top);
        top > 30 || top < 0 ? printf("Scelta errata!\n") : printf("Inserisci %d numeri: ", top);
    } while(top > 30 || top < 0);

    //Input
    do {
        scanf("%d", &V[n]);
        n++;
    } while(n < top);

    sottoSequenze(V, top);
    return 0;
}

void sottoSequenze(int V[], int N)
{
    int m = maximum(V, N);
    int i, l, counter = 0;

    for (i = 0; i < N; i++)
    {
        if (V[i] != 0)
            counter ++;
        if (V[i] == 0 || i == N - 1)
        {
            if(counter == m)
            {
                for(l=i-m; l<i; l++)
                {
                    if (i == N - 1 && V[i] != 0)
                        printf("%d ", V[l+1]);
                    else
                        printf("%d ", V[l]);
                }
                printf("\n");
            }
            counter = 0;
        }
    }
}

int maximum(int V[], int N)
{
    int i, m = 0, temp = 0;
    for(i = 0; i < N; i++)
    {
        if(V[i] != 0)
            temp++;
        if (V[i] == 0 || i == N - 1)
        {
            if(temp > m)
                m = temp;
            temp = 0;
        }
    }
    return m;
}