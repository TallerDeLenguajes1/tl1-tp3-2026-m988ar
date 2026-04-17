#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 150
#define NOMBRES 5

void mostrarPersonas(char **nombres);
int buscarNombre(char **nombres, char *clave);

int main(){
    char buff [MAX];
    char clave [MAX];
    char *nombres [NOMBRES];
    int idPalabraClave;

    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre:");
        gets(buff);
        //El "+1 es por el enter o caracter nulo al final del gets"
        nombres[i] = (char *) malloc(strlen(buff)*sizeof(char) + 1);
        strcpy(nombres[i], buff);
    }

    mostrarPersonas(nombres);

    printf("\nIngrese la paabra clave para buscar el nombre:\n");
    gets(clave);

    if ((idPalabraClave = buscarNombre(nombres, clave)) >= 0)
    {
        printf("\nEl nombre que coincide es %s\n", nombres[idPalabraClave]);
    }
    else
    {
        printf("\nNo hay nombres que coincidadn con la palabra clave\n");
    }
    

    return 0;
}

void mostrarPersonas(char **nombres){
    for (int i = 0 ; i < NOMBRES; i++)
    {
        printf("\n%s\n",nombres[i]);
    }
}

int buscarNombre(char **nombres, char *clave){
    
    for (int i = 0; i < NOMBRES; i++)
    {
        char *verificar = strstr(nombres[i], clave);
        if (verificar != NULL)
        {
             return i;
        }
    }
    return -1;
}