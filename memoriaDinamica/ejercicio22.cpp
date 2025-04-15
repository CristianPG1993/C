/*
=======================================================
🧪 EJERCICIO 5 - AÑADIR PRODUCTOS A UN ARRAY DINÁMICO
=======================================================

1. Crea una estructura llamada `Producto` que tenga:
   - nombre (string)
   - precio (float)
   - unidadesEnStock (int)

2. Crea un array dinámico con 2 productos.
3. Pide al usuario que introduzca nombre, precio y stock de cada producto.
4. Luego, pide un producto adicional.
5. Crea un nuevo array dinámico con espacio para 3 productos.
6. Copia los 2 productos anteriores al nuevo array.
7. Añade el nuevo producto al final.
8. Libera la memoria del array anterior.
9. Redirige el puntero original al nuevo array.
10. Muestra la lista completa de productos (nombre, precio, stock).

🎯 Objetivo: reforzar el uso de estructuras + arrays dinámicos + ampliación.
*/


#include <iostream>
#include <string>
#include <iomanip> // Para mostrar precios con 2 decimales
using namespace std;

// Paso 1: Definimos la estructura Producto
struct Producto {
    string nombre;
    float precio;
    int unidadesEnStock;
};

int main() {
    // Paso 2: Creamos un array dinámico de 2 productos
    Producto* productos = new Producto[2];

    // Paso 3: Pedimos los datos de los 2 productos
    cin.ignore(); // Limpiar el buffer antes del primer getline

    for (int i = 0; i < 2; i++) {
        cout << "\nProducto " << i + 1 << ":" << endl;

        cout << "Nombre: ";
        getline(cin, productos[i].nombre);

        cout << "Precio: ";
        cin >> productos[i].precio;

        cout << "Stock: ";
        cin >> productos[i].unidadesEnStock;

        cin.ignore(); // Limpiar salto de línea para el siguiente getline
    }

    // Paso 4: Pedimos los datos de un nuevo producto
    Producto nuevoProducto;

    cout << "\nIntroduce el tercer producto:\n";

    cout << "Nombre: ";
    getline(cin, nuevoProducto.nombre);

    cout << "Precio: ";
    cin >> nuevoProducto.precio;

    cout << "Stock: ";
    cin >> nuevoProducto.unidadesEnStock;

    // Paso 5: Creamos un nuevo array con espacio para 3 productos
    Producto* nuevoArray = new Producto[3];

    // Paso 6: Copiamos los 2 productos originales
    for (int i = 0; i < 2; i++) {
        nuevoArray[i] = productos[i];
    }

    // Paso 7: Añadimos el nuevo producto
    nuevoArray[2] = nuevoProducto;

    // Paso 8: Liberamos el array original
    delete[] productos;

    // Paso 9: Redirigimos el puntero original al nuevo array
    productos = nuevoArray;

    // Paso 10: Mostramos el inventario completo
    cout << "\n📦 Inventario completo:\n";

    for (int i = 0; i < 3; i++) {
        cout << "\nProducto " << i + 1 << ":\n";
        cout << "Nombre: " << productos[i].nombre << endl;
        cout << fixed << setprecision(2); // Mostrar precio con 2 decimales
        cout << "Precio: " << productos[i].precio << " euros" << endl;
        cout << "Stock: " << productos[i].unidadesEnStock << " unidades" << endl;
    }

    // Paso 11: Liberamos memoria final
    delete[] productos;

    return 0;
}
