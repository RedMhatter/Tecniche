#include <stdio.h>
#define MAXN 100

void selectionSort(int sort[], int length);
void insertionSort(int sort[], int length);
void shellSort(int sort[], int length);
void readSequence(int sort[], int length, FILE *fin);
void zero(int sort[], int length);
void copy(int sort[], int temp[], int length);

int main() {
    FILE *fin;
    int nr, i, length, j;
    int sort[MAXN];

    if((fin = fopen("sort.txt", "r")) == NULL)
        return 1;

    fscanf(fin, "%d", &nr);
    for (i=0; i<nr; i++)
    {
        fscanf(fin, "%d", &length);\
        printf("Sequenza n. %d\n\n", i+1);
        readSequence(sort, length, fin);
        selectionSort(sort, length);
        insertionSort(sort, length);
        shellSort(sort, length);
        zero(sort, length);
    }

    return 0;
}

void zero(int sort[], int length)
{
    int i;
    for(i = 0; i<length; i++)
        sort[i] = 0;
}

void copy(int sort[], int temp[], int length)
{
    int i;
    for(i = 0; i<length; i++)
        temp[i] = sort[i];
}

void readSequence(int sort[], int length, FILE *fin)
{
    int i;
    for(i=0; i<length; i++)
        fscanf(fin, "%d", &sort[i]);
}

void selectionSort(int sort[], int length)
{
    int i, j, min, t;
    int scambi=0, i_esterno=0, i_interno[length], i_internosum=0, i_tot=0;
    int temp[MAXN];
    zero(i_interno, length);
    copy(sort, temp, length);

    for(i=0; i<length-1; i++)
    {
        i_esterno++;
        min = i;
        for(j=i; j<length; j++)
        {
            i_interno[i]++;
            i_internosum++;
            if(temp[j]<temp[min])
                min = j;
        }

        if (min != i)
        {
            t = temp[i];
            temp[i] = temp[min];
            temp[min] = t;
            scambi++;
        }
    }
    i_tot = i_internosum + i_esterno;

    printf("Selection Sort:\n");
    printf("Numero di scambi: %d\n", scambi);
    printf("Numero di iterazioni del ciclo esterno: %d\n", i_esterno);
    printf("Numero di iterazioni del ciclo interno: \n");
    for(i=0; i<length; i++)
        printf("Passo %d: %d\t", i+1, i_interno[i]);
    printf("\nNumero totale di iterazioni: %d\n\n", i_tot);

}

void insertionSort(int sort[], int length)
{
    int i, j, min, check=0;
    int scambi=0, i_esterno=0, i_interno[length], i_internosum=0, i_tot=0;
    int temp[MAXN];
    zero(i_interno, length);
    copy(sort, temp, length);

    for (i=1; i<length; i++)
    {
        check = 0;
        i_esterno++;
        min = temp[i];
        j = i-1;
        while(j>=0 && temp[j]>min)
        {
            i_interno[i-1]++;
            i_internosum++;
            scambi++;
            temp[j+1] = temp[j];
            j--;
            check = 1;
        }
        if(check==1)
        {
            temp[j+1] = min;
            scambi++;
        }
    }
    i_tot = i_internosum + i_esterno;

    printf("Insertion Sort:\n");
    printf("Numero di scambi: %d\n", scambi);
    printf("Numero di iterazioni del ciclo esterno: %d\n", i_esterno);
    printf("Numero di iterazioni del ciclo interno: \n");
    for(i=0; i<length; i++)
        printf("Passo %d: %d\t", i+1, i_interno[i]);
    printf("\nNumero totale di iterazioni: %d\n\n", i_tot);
}

void shellSort(int sort[], int length)
{
    int i, j, min, h=0, passo=0, check=0;
    int scambi=0, i_esterno=0, i_interno[length], i_internosum=0, i_tot=0;
    int temp[MAXN];
    zero(i_interno, length);
    copy(sort, temp, length);

    //Sequenza di Knuth
    while (h < length/3)
        h = 3*h+1;

    while(h>=1)
    {
        for (i=h; i<length; i++)
        {
            check =0;
            i_esterno++;
            min = temp[i];
            j = i;
            while(j >= h && temp[j-h]>min)
            {
                i_interno[passo]++;
                i_internosum++;
                scambi++;
                temp[j] = temp[j-h];
                j -= h;
            }
            if(check==1)
            {
                temp[j] = min;
                scambi++;
            }
        }
        passo++;
        h = h/3;
    }
    i_tot = i_internosum + i_esterno;

    printf("Shell Sort:\n");
    printf("Numero di scambi: %d\n", scambi);
    printf("Numero di iterazioni del ciclo esterno: %d\n", i_esterno);
    printf("Numero di iterazioni del ciclo interno: \n");
    for(i=0; i<passo; i++)
        printf("Passo %d: %d\t", i+1, i_interno[i]);
    printf("\nNumero totale di iterazioni: %d\n\n", i_tot);
}