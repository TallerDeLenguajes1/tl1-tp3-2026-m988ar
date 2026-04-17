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

float calcularCostoProducto(Producto *Productos);
void mostrarClientes(Cliente *clientes, int cant);


int main(){
    srand(time(NULL));
    int cantClientes;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    Cliente *clientesArreglo;
    char buff[MAX];

    printf("-------MENU-------\n\n\nIngrese la cantidad de clientes:");
    //Reserva de memoria para la cantidad de clientes
    scanf("%d", &cantClientes);
    while (getchar() != '\n');
    clientesArreglo =(Cliente *) malloc(cantClientes * sizeof(Cliente));
    printf("\nIngrese el nombre de los clientes\n");
    //Reserva de memoria para los datos del cliente
    for (int i = 0; i < cantClientes; i++)
    {
        clientesArreglo[i].ClienteID = i;
        fgets(buff, sizeof(buff), stdin);
        buff[strcspn(buff, "\n")] = '\0';
        clientesArreglo[i].NombreCliente = (char *)malloc(strlen(buff) * sizeof(char) + 1);
        strcpy(clientesArreglo[i].NombreCliente, buff);
        clientesArreglo[i].CantidadProductosAPedir = (rand() % 5) + 1;
        clientesArreglo[i].Productos =(Producto *) malloc(clientesArreglo[i].CantidadProductosAPedir * sizeof(Producto));
        //Carga de productos
        for (int j = 0; j < clientesArreglo[i].CantidadProductosAPedir; j++)
        {
            clientesArreglo[i].Productos[j].ProductoID = j;
            clientesArreglo[i].Productos[j].Cantidad = (rand()%10) + 1;
            clientesArreglo[i].Productos[j].TipoProducto = TiposProductos[rand()%5];
            clientesArreglo[i].Productos[j].PrecioUnitario = (rand()%(100 - 10 + 1) + 10);
        }
    }
    mostrarClientes(clientesArreglo, cantClientes);
    
    //Libero la memoria reservada
    for (int i = 0; i < cantClientes; i++)
    {
        free(clientesArreglo[i].NombreCliente);
        free(clientesArreglo[i].Productos);
    }
    free (clientesArreglo);
}

void mostrarClientes(Cliente *clientes, int cant){

    for (int i = 0; i < cant; i++)
    {
        float precioTotal = 0;
        //Mostrar datos del/el cliente/s
        printf("\n--------------------------\n\nNombre del cliente: %s\nId: %d\n",clientes[i].NombreCliente, clientes[i].ClienteID);
        printf("Cantidad de Productos a pedir: %d\n", clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            //Mostrar datos del o los productos de cada cliente
            printf("----PRODUCTOS----\n--Producto: %s--\n",clientes[i].Productos[j].TipoProducto);
            printf("Id del producto: %d\nCantidad pedida:%d\n", clientes[i].Productos[j].ProductoID, clientes[i].Productos[j].Cantidad);
            printf("Precio unitario del producto:%f\n", clientes[i].Productos[j].PrecioUnitario);
            precioTotal += calcularCostoProducto(clientes[i].Productos);
        }
        printf("TOTAL A PAGAR: $%f", precioTotal);
    }
    
}

float calcularCostoProducto(Producto *Productos){
    float total = Productos->Cantidad * Productos->PrecioUnitario;
    return total;
}