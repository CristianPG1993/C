/*
===============================================
🧪 EJERCICIO 2 - AÑADIR NOMBRES A UN ARRAY DINÁMICO
===============================================

1. Crea un array dinámico de tipo string con 2 posiciones.
2. Pide al usuario que introduzca 2 nombres (uno por cada posición).
3. Luego, pide un tercer nombre.
4. Crea un nuevo array dinámico de 3 strings.
5. Copia los 2 nombres antiguos al nuevo array.
6. Guarda el nuevo nombre al final del array.
7. Libera la memoria del array anterior.
8. Asigna el nuevo array al puntero original.
9. Muestra todos los nombres guardados.

👉 Este ejercicio es igual que el anterior pero usando `string` para que refuerces el concepto con tipos más complejos.
*/


#include <iostream>
#include <string>
using namespace std;

int main() {
    // Paso 1: Crear array dinámico para 2 nombres
    string* nombres = new string[2];

    // Paso 2: Pedimos los 2 primeros nombres
    cin.ignore(); // Limpiamos el buffer antes del primer getline
    for (int i = 0; i < 2; i++) {
        cout << "\nIntroduce el nombre " << i + 1 << ": ";
        getline(cin, nombres[i]);
    }

    // Paso 3: Pedir un tercer nombre
    string nuevoNombre;
    cout << "\nIntroduce el tercer nombre: ";
    getline(cin, nuevoNombre);

    // Paso 4: Crear nuevo array con espacio para 3 nombres
    string* nuevoArray = new string[3];

    // Paso 5: Copiar los 2 nombres originales al nuevo array
    for (int i = 0; i < 2; i++) {
        nuevoArray[i] = nombres[i];
    }

    // Paso 6: Guardar el nuevo nombre al final
    nuevoArray[2] = nuevoNombre;

    // Paso 7: Liberar memoria del array original
    delete[] nombres;

    // Paso 8: Redirigir el puntero al nuevo array
    nombres = nuevoArray;

    // Paso 9: Mostrar los nombres actualizados
    cout << "\n📋 Lista de nombres actualizada:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Nombre " << i + 1 << ": " << nombres[i] << endl;
    }

    // Paso 10: Liberar memoria al final
    delete[] nombres;

    return 0;
}
