/*
Fecha: 02/09/2024
Nombre del equipo: Sharks
Integrantes:
    De La Cruz Perez Brandon
    Gonzalez Ramon Marco Antonio
    González Tetuán Héctor David
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){

    int numRandom, numGuess, tries=0;

    srand(time(NULL));

    numRandom = rand();

    printf("Adivina un numero positivo: ");

    while(1){

        scanf("%d",&numGuess);

        if(numGuess == numRandom)
            break;

        if(numGuess > numRandom)
            printf("Te pasaste\n");

        if(numGuess < numRandom)
            printf("Te falta\n");

        tries++;

        printf("intenta de nuevo\n");

    }

    printf("Felicidades, acertaste (numero de intentos: %d)",tries);


}