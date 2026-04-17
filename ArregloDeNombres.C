#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 150
#define NOMBRES 5

void mostrarPersonas(char **nombres);
int buscarNombrePalabra(char **nombres, char *clave);

void buscarNombreId(char **nombres, int id);

int main()
{
    char buff[MAX];
    char clave[MAX];
    char *nombres[NOMBRES];
    int idPalabraClave;
    int id, i;

    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el nombre:");
        gets(buff);
        // El "+1 es por el enter o caracter nulo al final del gets"
        nombres[i] = (char *)malloc(strlen(buff) * sizeof(char) + 1);
        strcpy(nombres[i], buff);
    }
//menu
    mostrarPersonas(nombres);
    printf("Seleccione de que manera desea buscar el nombre\n1)Id\n2)Palabra clave\n");
    scanf("%d", &i);

    switch (i)
    {
    case 1: // Id
        printf("Ingrese el ID que quiere buscar: ");
        scanf("%d", &id);
        buscarNombreId(nombres, id);

        break;
    case 2: // Palabra clave
        printf("\nIngrese la paabra clave para buscar el nombre:\n");
        while (getchar() != '\n');
        fgets(clave, sizeof(clave), stdin);
        clave[strcspn(clave, "\n")] = '\0';

        if ((idPalabraClave = buscarNombrePalabra(nombres, clave)) >= 0)
        {
            printf("\nEl nombre que coincide es %s\n", nombres[idPalabraClave]);
        }
        else
        {
            printf("\nNo hay nombres que coincidan con la palabra clave\n");
        }

        break;

    default:
        printf("\nerror 404 :(\n");
        break;
    }

    // Libero memoria
    for (int i = 0; i < NOMBRES; i++)
    {
        free(nombres[i]);
    }

    return 0;
}

void mostrarPersonas(char **nombres)
{
    for (int i = 0; i < NOMBRES; i++)
    {
        printf("\n%s\n", nombres[i]);
    }
}

void buscarNombreId(char **nombres, int id)
{
    for (int i = 0; i < NOMBRES; i++)
    {
        if (i == id)
        {
            printf("\nEl nombre de id %d es: %s\n", id, nombres[i]);
            return;
        }
    }
    printf("\nNo se encontro el valor buscado\n");
}

int buscarNombrePalabra(char **nombres, char *clave)
{

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