#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 150
#define NOMBRES 5

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
}