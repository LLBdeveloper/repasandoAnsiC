#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUCTOS 100
#define NOMBRE_ARCHIVO "inventario.dat"

typedef struct {
    int id;
    char nombre[50];
    float precio;
    int cantidad;
} Producto;

Producto inventario[MAX_PRODUCTOS];
int totalProductos = 0;

// Prototipos de funciones
void cargarInventario();
void guardarInventario();
void menuPrincipal();
void agregarProducto();
void listarProductos();
void buscarProducto();
void editarProducto();
void eliminarProducto();

int main() {
    cargarInventario();
    menuPrincipal();
    return 0;
}

// Carga los datos del archivo al array
void cargarInventario() {
    FILE *archivo = fopen(NOMBRE_ARCHIVO, "rb");
    if (archivo == NULL) {
        printf("Archivo no encontrado. Se creara uno nuevo.\n");
        return;
    }

    totalProductos = fread(inventario, sizeof(Producto), MAX_PRODUCTOS, archivo);
    fclose(archivo);
}

// Guarda el array en el archivo
void guardarInventario() {
    FILE *archivo = fopen(NOMBRE_ARCHIVO, "wb");
    if (archivo == NULL) {
        printf("Error al guardar el archivo!\n");
        return;
    }

    fwrite(inventario, sizeof(Producto), totalProductos, archivo);
    fclose(archivo);
}

// Menú interactivo
void menuPrincipal() {
    int opcion;
    do {
        printf("\n=== SISTEMA DE INVENTARIO ===\n");
        printf("1. Agregar producto\n");
        printf("2. Listar productos\n");
        printf("3. Buscar producto\n");
        printf("4. Editar producto\n");
        printf("5. Eliminar producto\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: agregarProducto(); break;
            case 2: listarProductos(); break;
            case 3: buscarProducto(); break;
            case 4: editarProducto(); break;
            case 5: eliminarProducto(); break;
            case 0: guardarInventario(); break;
            default: printf("Opcion invalida!\n");
        }
    } while (opcion != 0);
}

// Funciones CRUD
void agregarProducto() {
    if (totalProductos >= MAX_PRODUCTOS) {
        printf("Inventario lleno!\n");
        return;
    }

    Producto p;
    printf("\n=== AGREGAR PRODUCTO ===\n");
    p.id = totalProductos + 1;

    printf("Nombre: ");
    scanf(" %[^\n]", p.nombre); // Lee espacios

    printf("Precio: ");
    scanf("%f", &p.precio);

    printf("Cantidad: ");
    scanf("%d", &p.cantidad);

    inventario[totalProductos++] = p;
    printf("Producto agregado (ID: %d)\n", p.id);
}

void listarProductos() {
    printf("\n=== LISTA DE PRODUCTOS ===\n");
    printf("ID\tNombre\t\tPrecio\tCantidad\n");
    for (int i = 0; i < totalProductos; i++) {
        printf("%d\t%s\t%.2f\t%d\n",
               inventario[i].id,
               inventario[i].nombre,
               inventario[i].precio,
               inventario[i].cantidad);
    }
}

void buscarProducto() {
    int id;
    printf("\nIngrese ID del producto: ");
    scanf("%d", &id);

    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].id == id) {
            printf("\nID: %d\nNombre: %s\nPrecio: %.2f\nCantidad: %d\n",
                   inventario[i].id,
                   inventario[i].nombre,
                   inventario[i].precio,
                   inventario[i].cantidad);
            return;
        }
    }
    printf("Producto no encontrado!\n");
}

void editarProducto() {
    int id;
    printf("\nIngrese ID del producto a editar: ");
    scanf("%d", &id);

    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].id == id) {
            printf("\nEDITANDO: %s\n", inventario[i].nombre);
            printf("Nuevo nombre: ");
            scanf(" %[^\n]", inventario[i].nombre);

            printf("Nuevo precio: ");
            scanf("%f", &inventario[i].precio);

            printf("Nueva cantidad: ");
            scanf("%d", &inventario[i].cantidad);

            printf("Producto actualizado!\n");
            return;
        }
    }
    printf("Producto no encontrado!\n");
}

void eliminarProducto() {
    int id;
    printf("\nIngrese ID del producto a eliminar: ");
    scanf("%d", &id);

    for (int i = 0; i < totalProductos; i++) {
        if (inventario[i].id == id) {
            for (int j = i; j < totalProductos - 1; j++) {
                inventario[j] = inventario[j + 1];
            }
            totalProductos--;
            printf("Producto eliminado!\n");
            return;
        }
    }
    printf("Producto no encontrado!\n");
}
