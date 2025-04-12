/*
    EJERCICIO: Gestión de inventario de productos

    Objetivo:
    - Crear un sistema para registrar N productos.
    - Cada producto debe tener:
        - Nombre
        - Precio
        - Cantidad en stock

    Funciones requeridas:
    1. Cargar productos (nombre, precio, stock)
    2. Mostrar todos los productos registrados
    3. Calcular y mostrar el valor total del inventario
    4. Mostrar el producto con mayor valor (precio × stock)
    5. Liberar memoria

    Requisitos:
    - Usar struct Producto
    - Usar memoria dinámica con new y delete[]
    - Modularizar todo en funciones
*/

#include <iostream>
using namespace std;

// Estructura que representa un producto del inventario
struct Producto {
    string nombre;   // Nombre del producto
    float precio;    // Precio por unidad
    int cantidad;    // Unidades disponibles en stock
};

// Función que permite al usuario cargar los datos de cada producto
void cargarProductos(Producto* lista, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "-----------------------------" << endl;
        cout << "Producto " << i + 1 << ": ";
        cin >> lista[i].nombre;
        cout << "Precio: ";
        cin >> lista[i].precio;
        cout << "Cantidad: ";
        cin >> lista[i].cantidad;
        cout << "-----------------------------" << endl;
    }
}

// Función que muestra todos los productos registrados
void mostrarProductos(Producto* lista, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "-----------------------------" << endl;
        cout << "Inventario: " << endl;
        cout << "Nombre: " << lista[i].nombre << endl;
        cout << "Precio: " << lista[i].precio << " €." << endl;
        cout << "Cantidad: " << lista[i].cantidad << endl;
    }
}

// Función que calcula el valor total del inventario (precio × cantidad de cada producto)
float calcularInventario(Producto* lista, int cantidad) {
    float inventarioTotal = 0;

    for (int i = 0; i < cantidad; i++) {
        float precioTotal = lista[i].precio * lista[i].cantidad;
        inventarioTotal += precioTotal;
    }

    return inventarioTotal;
}

// Función que determina y muestra el producto con mayor valor (precio × cantidad)
void productoMayorValor(Producto* lista, int cantidad) {
    float mayorValor = lista[0].precio * lista[0].cantidad;
    string nombreProductoMayor = lista[0].nombre;  // ← Inicializar con el primero

    for (int i = 1; i < cantidad; i++) {
        float valorActual = lista[i].precio * lista[i].cantidad;

        if (valorActual > mayorValor) {
            mayorValor = valorActual;
            nombreProductoMayor = lista[i].nombre;
        }
    }

    cout << "El producto de mayor valor es: " << nombreProductoMayor 
         << " con un valor total de " << mayorValor << " €." << endl;
}

// Función principal
int main() {
    int cantidad;

    // Solicitar al usuario cuántos productos desea introducir
    cout << "¿Cuántos productos tiene tu inventario? ";
    cin >> cantidad;

    // Reservar memoria dinámica para los productos
    Producto* lista = new Producto[cantidad];

    // Llamar a las funciones para cargar y mostrar los productos
    cargarProductos(lista, cantidad);
    cout << "--------------------------" << endl;
    mostrarProductos(lista, cantidad);

    // Calcular y mostrar el valor total del inventario
    float inventarioTotal = calcularInventario(lista, cantidad);
    cout << "El valor del inventario es: " << inventarioTotal << " €." << endl;

    // Mostrar el producto con mayor valor
    productoMayorValor(lista, cantidad);

    // Liberar la memoria dinámica utilizada
    delete[] lista;

    return 0;
}
