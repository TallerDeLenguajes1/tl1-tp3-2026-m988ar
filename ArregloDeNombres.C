#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 150
#define NOMBRES 5

void mostrarPersonas(char **nombres);

int main(){
    char buff [MAX];
    char *nombres [NOMBRES];

    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre:");
        gets(buff);
        //El "+1 es por el enter o caracter nulo al final del gets"
        nombres[i] = (char *) malloc(strlen(buff)*sizeof(char) + 1);
        strcpy(nombres[i], buff);
    }

    mostrarPersonas(nombres);

    return 0;
}

void mostrarPersonas(char **nombres){
    for (int i = 0 ; i < NOMBRES; i++)
    {
        printf("\n%s\n",nombres[i]);
    }
}