#include <stdio.h>
#include <string.h>
#define MAXL 30
#define MAX 1000

typedef struct {
  char codice_tratta[MAXL];
  char partenza[MAXL];
  char destinazione[MAXL];
  char data[MAXL];
  char ora_partenza[MAXL];
  char ora_arrivo[MAXL];
  int ritardo;
} corse;

typedef enum {
    r_date, r_partenza, r_capolinea, r_ritardo, r_ritardo_tot, r_fine, r_err
} comando_e;

void leggiTabella(int nr, corse log[], FILE *fin);
void stampa(int i, corse log[]);
void menuParola(corse log[], int nr);
void date(corse log[], int nr);
void partenza(corse log[], int nr);
void destinazione(corse log[], int nr);
void ritardo(corse log[], int nr);
void ritardo_tot(corse log[], int nr);
comando_e leggiComando();

int main() {
    FILE *fin;
    int nr;
    corse log[MAX];

    if((fin = fopen("corse.txt", "r")) == NULL)
    {
        printf("Impossibile aprire il file.");
        return 1;
    }

    fscanf(fin, "%d", &nr);
    leggiTabella(nr, log, fin);
    fclose(fin);

    menuParola(log, nr);

    return 0;
}

void menuParola(corse log[], int nr)
{
    comando_e codice;
    int continua = 1;

    while(continua)
    {
        fflush(stdin);
        codice = leggiComando();
        switch (codice)
        {
            case r_date: date(log, nr);
                break;
            case r_partenza: partenza(log, nr);
                break;
            case r_capolinea: destinazione(log, nr);
                break;
            case r_ritardo: ritardo(log, nr);
                break;
            case r_ritardo_tot: ritardo_tot(log, nr);
                break;
            case r_fine: continua = 0;
                break;
            case r_err:
            default:
                printf("Scelta inesistente\n");
        }
    }
}

comando_e leggiComando()
{
    comando_e c;
    char scelta[MAXL];
    char *tabella[r_err] = {
            "date", "partenza", "capolinea", "ritardo", "ritardo_tot", "fine"
    };

    printf("Inserisci la tua scelta: ");
    scanf("%s", scelta);
    c = r_date;
    while(c<r_err && strcmp(scelta, tabella[c]) != 0)
        c++;
    return c;
}

void date(corse log[], int nr)
{
    int i;
    char inizio[MAXL], fine[MAXL];
    scanf("%s %s", inizio, fine);

    for(i=0; i<nr; i++)
        if(strcmp(log[i].data, inizio) >= 0 && strcmp(log[i].data, fine) <= 0)
            stampa(i, log);
}

void partenza(corse log[], int nr)
{
    int i;
    char fermata[MAXL];
    scanf("%s", fermata);

    for(i=0; i<nr; i++)
        if(strcmp(log[i].partenza, fermata) == 0)
            stampa(i, log);
}

void destinazione(corse log[], int nr)
{
    int i;
    char destinazione[MAXL];
    scanf("%s", destinazione);

    for(i=0; i<nr; i++)
        if(strcmp(log[i].destinazione, destinazione) == 0)
            stampa(i, log);
}

void ritardo(corse log[], int nr)
{
    int i;
    char inizio[MAXL], fine[MAXL];
    scanf("%s %s", inizio, fine);

    for(i=0; i<nr; i++)
        if((strcmp(log[i].data, inizio) >= 0 && strcmp(log[i].data, fine) <= 0) && log[i].ritardo>0)
            stampa(i, log);
}

void ritardo_tot(corse log[], int nr)
{
    int i, ritardo = 0;
    char tratta[MAXL];
    scanf("%s", tratta);

    for(i=0; i<nr; i++)
        if(strcmp(log[i].codice_tratta, tratta) == 0)
            ritardo += log[i].ritardo;
    printf("Ritardo complessivo di %s: %d\n", tratta, ritardo);
}

void stampa(int i, corse log[])
{
    printf("%s %s %s %s %s %s %d\n", log[i].codice_tratta, log[i].partenza, log[i].destinazione,
           log[i].data, log[i].ora_partenza, log[i].ora_arrivo, log[i].ritardo);
}

void leggiTabella(int nr, corse log[], FILE *fin)
{
    int i;
    for(i=0; i<nr; i++)
        fscanf(fin, "%s %s %s %s %s %s %d", log[i].codice_tratta, log[i].partenza, log[i].destinazione,
               log[i].data, log[i].ora_partenza, log[i].ora_arrivo, &log[i].ritardo);
}