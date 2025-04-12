/*
    EJERCICIO: Filtros y ordenación de productos

    Objetivo:
    1. Registrar N productos (nombre, precio, cantidad).
    2. Mostrar todos los productos.
    3. Mostrar los productos con valor total (precio × cantidad) superior a 100 €.
    4. Mostrar los productos con menos de 5 unidades en stock.
    5. Ordenar los productos por valor total (precio × cantidad) de mayor a menor.
    6. Mostrar el inventario ordenado.
    
    Requisitos:
    - Usar struct Producto
    - Usar memoria dinámica con new y delete[]
    - Modularizar cada funcionalidad
    - Usar un algoritmo de ordenación sencillo (burbuja o selección)
*/


#include <iostream>
using namespace std;

// Estructura que representa un producto del inventario
struct Producto {
    string nombre;   // Nombre del producto
    float precio;    // Precio por unidad
    int cantidad;    // Cantidad en stock
};

// Función que permite al usuario cargar los datos de los productos
void cargarProductos(Producto* lista, int cantidad) {
    cout << "--------------------------------------" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Introduce el producto " << i + 1 << ": ";
        cin >> lista[i].nombre;
        cout << "Introduce el precio: ";
        cin >> lista[i].precio;
        cout << "Introduce la cantidad: ";
        cin >> lista[i].cantidad;
    }
}

// Función que muestra todos los productos del inventario
void mostrarProductos(Producto* lista, int cantidad) {
    cout << "-------------------------------------" << endl;
    cout << "\n=== Inventario de productos ===\n";

    for (int i = 0; i < cantidad; i++) {
        cout << "\n--------------------------" << endl;
        cout << "Producto " << i + 1 << endl;
        cout << "Nombre  : " << lista[i].nombre << endl;
        cout << "Precio  : " << lista[i].precio << " euros" << endl;
        cout << "Cantidad: " << lista[i].cantidad << endl;
        cout << "Total   : " << lista[i].precio * lista[i].cantidad << " euros" << endl;
    }
}

// Función que muestra los productos cuyo valor total supera los 100 euros
void mostrarProductosCaros(Producto* lista, int cantidad) {
    cout << "--------------------------------------" << endl;
    cout << "Los productos con valor total por encima de 100 son:" << endl;

    for (int i = 0; i < cantidad; i++) {
        float valorTotal = lista[i].precio * lista[i].cantidad;

        if (valorTotal > 100) {
            cout << "- " << lista[i].nombre << " ("
                 << lista[i].precio << " euros x "
                 << lista[i].cantidad << " = "
                 << valorTotal << " euros)\n";
        }
    }
}

// Función que muestra los productos con menos de 5 unidades en stock
void mostrarProductosMenorStock(Producto* lista, int cantidad) {
    cout << "Los productos con menos de 5 unidades son:" << endl;

    for (int i = 0; i < cantidad; i++) {
        if (lista[i].cantidad < 5) {
            cout << "- " << lista[i].nombre 
                 << " (" << lista[i].cantidad << " unidades)\n";
        }
    }
}

// Función que ordena los productos por valor total de mayor a menor
void ordenarPorValor(Producto* lista, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        for (int j = i + 1; j < cantidad; j++) {
            // Calcular el valor total de ambos productos
            float valorI = lista[i].precio * lista[i].cantidad;
            float valorJ = lista[j].precio * lista[j].cantidad;

            // Si el producto j tiene mayor valor, lo intercambiamos con el i
            if (valorJ > valorI) {
                Producto temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

// Función principal que gestiona el flujo del programa
int main() {
    int cantidad;

    // Pedir al usuario cuántos productos desea introducir
    cout << "¿Cuántos productos vas a introducir? ";
    cin >> cantidad;

    // Reservar memoria dinámica para almacenar los productos
    Producto* lista = new Producto[cantidad];

    // Cargar los datos de los productos
    cargarProductos(lista, cantidad);

    // Mostrar el inventario original
    cout << "\n=== INVENTARIO ORIGINAL ===\n";
    mostrarProductos(lista, cantidad);

    // Mostrar productos con valor total > 100
    cout << "\n=== PRODUCTOS CAROS (+100€) ===\n";
    mostrarProductosCaros(lista, cantidad);

    // Mostrar productos con bajo stock (<5)
    cout << "\n=== PRODUCTOS CON BAJO STOCK (<5) ===\n";
    mostrarProductosMenorStock(lista, cantidad);

    // Ordenar por valor total y mostrar de nuevo el inventario
    cout << "\n=== INVENTARIO ORDENADO POR VALOR TOTAL ===\n";
    ordenarPorValor(lista, cantidad);
    mostrarProductos(lista, cantidad);

    // Liberar la memoria dinámica
    delete[] lista;
    return 0;
}
