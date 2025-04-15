/*
===========================================================
🧪 EJERCICIO 3 - AÑADIR UN NUEVO PRECIO A UN ARRAY DINÁMICO
===========================================================

1. Crea un array dinámico de tipo float con espacio para 2 precios.
2. Pide al usuario que introduzca los 2 precios iniciales.
3. Luego, pide un tercer precio adicional.
4. Crea un nuevo array dinámico con espacio para 3 precios.
5. Copia los 2 precios anteriores al nuevo array.
6. Añade el nuevo precio al final del array.
7. Libera la memoria del array original.
8. Redirige el puntero original al nuevo array.
9. Muestra todos los precios actualizados.

🎯 Objetivo: reforzar la ampliación de arrays dinámicos usando float.
*/


#include <iostream>
#include <iomanip> // Para setprecision
using namespace std;

int main() {
    // Paso 1: Crear un array dinámico de 2 precios
    float* precios = new float[2];

    // Paso 2: Pedir al usuario los 2 precios iniciales
    for (int i = 0; i < 2; i++) {
        cout << "\nIntroduce el precio " << i + 1 << ": ";
        cin >> precios[i];
    }

    // Paso 3: Pedir un nuevo precio adicional
    float precioNuevo;
    cout << "\nIntroduce el tercer precio: ";
    cin >> precioNuevo;

    // Paso 4: Crear un nuevo array dinámico con tamaño 3
    float* nuevoArray = new float[3];

    // Paso 5: Copiar los 2 precios anteriores al nuevo array
    for (int i = 0; i < 2; i++) {
        nuevoArray[i] = precios[i];
    }

    // Paso 6: Guardar el nuevo precio en la última posición
    nuevoArray[2] = precioNuevo;

    // Paso 7: Liberar memoria del array antiguo
    delete[] precios;

    // Paso 8: Redirigir el puntero original al nuevo array
    precios = nuevoArray;

    // Paso 9: Mostrar los precios actualizados
    cout << "\n📋 Lista de precios actualizada:\n";
    for (int i = 0; i < 3; i++) {
        cout << fixed << setprecision(2); // Mostrar 2 decimales
        cout << "Precio " << i + 1 << ": " << precios[i] << " €" << endl;
    }

    // Paso 10: Liberar memoria final
    delete[] precios;

    return 0;
}
