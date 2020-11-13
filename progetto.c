#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int main(){

char testo_chiaro[128];   /* Definisco le variabili*/
char chiave[128];
char testo_cifrato[128];
time_t t;
int scelta;

do{
printf("inserisci testo in chiaro minore di 128 caratteri:\n");
fgets(testo_chiaro, 128, stdin);      /*inserisco testo in chiaro nell'array*/
}while (strlen(testo_chiaro)-1==0);
if (!strchr(testo_chiaro, '\n')){
  while(fgetc(stdin) != '\n');
  printf("La stringa inserita è: %s\n", testo_chiaro);
}else {
  printf("La stringa inserita è: %s", testo_chiaro);
}

printf("\nAdesso hai la possibilità di scegliere:\n-Se premi il tasto '0' il programma verrà terminato;\n-Se premi il tasto '1' dovrai scegliere la chiave con cui codificherai il testo in chiaro;\n-Se premi '2' la chiave verrà generata automaticamente.\n\n");
scanf("%d", &scelta); //creo menù di scelta //

switch (scelta) {
  case 0:         /*con il caso 0 il programma termina*/
  break;
  case 1:         /*con il caso 1 devo inserire manualmente la chiave che verrà utilizzata per criptare il testo in chiaro*/


  printf("la tua stringa da cifrare e' %s\n", testo_chiaro);

  printf("inserisci chiave di codifica:\n");
    scanf("%s", chiave);        /*inserisco chiave di codifica nell'array*/
  do{               /*se la chiave è inferiore al testo in chiaro fa riscrivere la chiave*/

    if(strlen(testo_cifrato)<strlen(testo_chiaro)){
      printf("la chiave deve avere tra %lu e 128 caratteri\n", strlen(testo_chiaro));
          scanf("%s", chiave);
    }
  }
  while(strlen(testo_cifrato)>=strlen(testo_chiaro));



for(int i=0;  i<strlen(chiave);  i++)     /*creo ciclo per poter calcolare cella per cella lo XOR*/
  {
  testo_cifrato[i] = testo_chiaro[i] ^ chiave[i];      /* Faccio il calcolo XOR tra testo in chiaro e chiave per ottenere il testo cifrato*/
  }
  printf("\nil codice criptato formato stringa :"); /*viene stampata la stringa criptata*/
  for(int i = 0;    i<strlen(chiave);   i++){
    if(testo_cifrato[i] >=0 && testo_cifrato[i] < 33){      /*tolgo i caratteri speciali*/
      printf("%c", testo_cifrato[i]+33);
    }
    else{
      printf("%c", testo_cifrato[i]);
    }
  }
  printf("\nil codice criptato in formato esadecimale: ");
  for(int i=0;    i<strlen(chiave);  i++)
  {
    printf("%x", testo_cifrato[i]);
  }
  for(int i=0;  i<strlen(chiave);  i++){             /*creo ciclo per per calcolare cella per cella lo XOR*/

  testo_chiaro[i] = testo_cifrato[i] ^ chiave[i];       /*faccio lo XOR tra testo cifrato e chiave per poter riottenere il testo in chiaro*/
  }
  printf("il codice criptato riportato in chiaro è:%s", testo_chiaro);    /*viene stampato il testo in chiaro*/
break;

case 2:
srand((unsigned)time(&t));            /* funzione per creare una chiave randomica */
for(int i = 0;    i<strlen(testo_chiaro);   i++)
{
  chiave[i] = (33+rand()%128);

}
printf("La chiave generata automaticamente in esadecimale:");
for(int i=0;  i<strlen(testo_chiaro);   i++)
printf("%x", chiave[i]);                          /*stampo la chiave in esadecimale*/

for(int i=0;    i<strlen(testo_chiaro);   i++){
  testo_cifrato[i]=testo_chiaro[i] ^ chiave[i];                     /*XOR tra testo in chiaro e chiave per trovare il testo cifrato*/
}
printf("\nil codice criptato in formato stringa: %s\n", testo_cifrato);
printf("il codice criptato in formato esadecimale:");
for(int i=0;    i<strlen(testo_cifrato);  i++)
{
  printf("%x", testo_cifrato[i]);                 /*stampo il testo cifrato in esadecimale*/
}
for(int i=0;    i<strlen(testo_chiaro);   i++){

  testo_chiaro[i]=testo_cifrato[i] ^ chiave[i];                 /*XOR tra testo cifrato e chiave per riottenere testo in chiaro*/
}
printf("\nil codice criptato riportato in chiaro:%s", testo_chiaro);
break;

}

  return 0;
}
