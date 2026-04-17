#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 150
#define NOMBRES 5

void mostrarPersonas(char **nombres);

void buscarNombre(char **nombres, int id);

int main(){
    char buff [MAX];
    char *nombres [NOMBRES];
    int id;

    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre:");
        gets(buff);
        //El "+1 es por el enter o caracter nulo al final del gets"
        nombres[i] = (char *) malloc(strlen(buff)*sizeof(char) + 1);
        strcpy(nombres[i], buff);
    }

    mostrarPersonas(nombres);

    printf("Ingrese el ID que quiere buscar: ");
    scanf("%d", &id);
    buscarNombre(nombres, id);

    return 0;
}

void mostrarPersonas(char **nombres){
    for (int i = 0 ; i < NOMBRES; i++)
    {
        printf("\n%s\n",nombres[i]);
    }
}

void buscarNombre(char **nombres, int id){
    for (int i = 0; i < NOMBRES; i++)
    {
        if (i == id)
        {
            printf("\nEl nombre de id %d es: %s\n",id, nombres[i]);
            return ;
        }
    }
    printf("\nNo se encontro el valor buscado\n");
}