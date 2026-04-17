#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 150
typedef struct{
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
}Producto;

typedef struct{
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
 // “CantidadProductosAPedir”
}Cliente;


int main(){
    srand(time(NULL));
    int cantClientes;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    Cliente *clientesArreglo;

    printf("-------MENU-------\n\n\nIngrese la cantidad de clientes:");
    scanf("%d", &cantClientes);
    clientesArreglo =(Cliente *) malloc(cantClientes * sizeof(Cliente));
    
}