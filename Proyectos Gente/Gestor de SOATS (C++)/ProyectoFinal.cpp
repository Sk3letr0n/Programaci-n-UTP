#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define num 1

using namespace std;

struct Cliente {
    char nombreApellido[40];
    char telefono[15]; // Cambio el tipo de int a char
    int documento;
};

// No se implementó a la final en el código por cuestiones de tiempo.
struct Vehiculo {
    int placa;
    int modelo;
    char marca[10];
    char ciudad[20];
};

struct Venta {
    char marca[10];
    int precio;
    time_t fechaVenta;
    char nombreCliente[40]; // Nombre del cliente que compró el SOAT
};

bool SOATExpirado(const time_t &fechaVenta) {
    // Calcular la diferencia en segundos entre la fecha actual y la fecha de venta
    time_t ahora = time(NULL);
    double diferencia = difftime(ahora, fechaVenta);

    // 3 días en segundos
    double tresDias = 3 * 24 * 60 * 60;

    return diferencia > tresDias;
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ingresarCliente() {
    FILE* archivo = fopen("clientes.txt", "ab");
    if (!archivo) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    Cliente cliente;

    printf("Ingrese Nombre y Apellido: ");
    limpiarBuffer(); // Limpiar el búfer de entrada
    fgets(cliente.nombreApellido, 40, stdin);
    cliente.nombreApellido[strcspn(cliente.nombreApellido, "\n")] = '\0'; // Eliminar el salto de línea

    printf("Ingrese Numero de telefono: ");
    fgets(cliente.telefono, 15, stdin);
    cliente.telefono[strcspn(cliente.telefono, "\n")] = '\0'; // Eliminar el salto de línea

    printf("Ingrese Documento: ");
    scanf("%d", &cliente.documento);
    limpiarBuffer(); // Limpiar el búfer de entrada

    fwrite(&cliente, sizeof(Cliente), 1, archivo);

    fclose(archivo);
}

void mostrarClientes() {
    FILE* archivo = fopen("clientes.txt", "rb");
    if (!archivo) {
        printf("Error al abrir el archivo.\n");
        return;
    }

    Cliente cliente;
    while (fread(&cliente, sizeof(Cliente), 1, archivo) == 1) {
        printf("Nombre y Apellido: %s\n", cliente.nombreApellido);
        printf("Numero de telefono: %s\n", cliente.telefono);
        printf("Documento: %d\n\n", cliente.documento);
    }

    fclose(archivo);
}

void venderSOAT() {
    FILE *marcasFile;
    Venta venta;
    int opcionMarca;
    int soatsVendidos = 0;

    marcasFile = fopen("Marcas.txt", "r");
    if (!marcasFile) {
        printf("No se puede abrir el archivo de marcas.\n");
        exit(1);
    } else {
        printf("Marcas disponibles:\n");
        int marcaIndex = 1;
        while (fscanf(marcasFile, "%s %d\n", venta.marca, &venta.precio) != EOF) {
            printf("%d. %s - Precio: %d\n", marcaIndex, venta.marca, venta.precio);
            marcaIndex++;
        }
        fclose(marcasFile);

        printf("Seleccione una marca (1-%d): ", marcaIndex - 1);
        scanf("%d", &opcionMarca);

        marcasFile = fopen("Marcas.txt", "r");
        marcaIndex = 1;
        while (fscanf(marcasFile, "%s %d\n", venta.marca, &venta.precio) != EOF) {
            if (marcaIndex == opcionMarca) {
                printf("\nHa seleccionado la marca: %s\n", venta.marca);
                printf("Precio del SOAT: %d\n", venta.precio);

                char confirmacion;
                printf("Desea comprar este SOAT? (s/n): ");
                scanf(" %c", &confirmacion);

                if (confirmacion == 's') {
                    time_t ahora = time(NULL);
                    venta.fechaVenta = ahora;
                    soatsVendidos++;
                    printf("\nCompra realizada!\n");

                    // Verificar si el cliente existe
                    FILE *clientesFile = fopen("clientes.txt", "r");
                    if (!clientesFile) {
                        printf("No se puede abrir el archivo de clientes.\n");
                        exit(1);
                    } else {
                        char nombreCliente[40];
                        bool clienteEncontrado = false;
                        printf("Ingrese Nombre y Apellido del cliente: ");
                        limpiarBuffer(); // Limpiar el búfer de entrada
                        fgets(nombreCliente, 40, stdin);
                        nombreCliente[strcspn(nombreCliente, "\n")] = '\0'; // Eliminar el salto de línea

                        Cliente cliente;
                        while (fread(&cliente, sizeof(Cliente), 1, clientesFile) == 1) {
                            if (strcmp(cliente.nombreApellido, nombreCliente) == 0) {
                                clienteEncontrado = true;
                                break;
                            }
                        }
                        fclose(clientesFile);

                        if (clienteEncontrado) {
                            // Guardar la venta en un archivo
                            FILE *ventasFile = fopen("Ventas.txt", "a");
                            fprintf(ventasFile, "Marca: %s Precio: %d Fecha de venta: %lld Cliente: %s\n", venta.marca, venta.precio, venta.fechaVenta, nombreCliente);
                            fclose(ventasFile);

                            // Verificar si el SOAT ha expirado
                            if (SOATExpirado(venta.fechaVenta)) {
                                printf("El SOAT ha expirado.\n");
                            } else {
                                printf("El SOAT no ha expirado.\n");
                            }
                        } else {
                            printf("El cliente no existe.\n");
                        }
                    }
                } else {
                    printf("\nCompra cancelada.\n");
                }
            }
            marcaIndex++;
        }
        fclose(marcasFile);
    }
}

void cantidadSOATsVendidos() {
    FILE *ventasFile;
    int soatsVendidos = 0;
    char marca[10];
    int precio;
    time_t fechaVenta;
    char nombreCliente[40];

    ventasFile = fopen("Ventas.txt", "r");
    if (!ventasFile) {
        printf("No se puede abrir el archivo de ventas.\n");
        exit(1);
    } else {
        while (fscanf(ventasFile, "Marca: %s Precio: %d Fecha de venta: %lld Cliente: %[^\n]\n", marca, &precio, &fechaVenta, nombreCliente) != EOF) {
            soatsVendidos++;
        }
        fclose(ventasFile);

        printf("Cantidad de SOATs vendidos: %d\n", soatsVendidos);
    }
}

int main() {
    int opcion = 0;

    while (opcion != 5) {
        system("cls");
        printf("MENU.\n\n");
        printf("1. Recoger datos de clientes.\n");
        printf("2. Mostrar datos de clientes.\n");
        printf("3. Vender SOATs.\n");
        printf("4. Registro de SOATs vendidos.\n");
        printf("5. Salida del programa.\n\n");

        printf("Digite una Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarCliente();
                break;

            case 2:
                mostrarClientes();
                break;

            case 3:
                venderSOAT();
                break;

            case 4:
                cantidadSOATsVendidos();
                break;

            case 5:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
        system("pause");
    }

    return 0;
}
