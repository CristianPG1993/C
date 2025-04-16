/*
=================================================================
📚 EJERCICIO 6 - AÑADIR LIBROS A UN ARRAY DINÁMICO DE INVENTARIO
=================================================================

1. Crea una estructura `Libro` con los siguientes campos:
   - título (string)
   - autor (string)
   - precio (float)

2. Crea un array dinámico con espacio para 2 libros.
3. Pide al usuario los datos de esos 2 libros.
4. Luego, pide los datos de un tercer libro adicional.
5. Crea un nuevo array dinámico de 3 libros.
6. Copia los 2 libros anteriores al nuevo array.
7. Añade el nuevo libro al final.
8. Libera el array original.
9. Redirige el puntero original al nuevo array.
10. Muestra el listado completo de libros (título, autor y precio).

🎯 Este ejercicio es para practicar otra vez la lógica de ampliación dinámica con estructuras simples.
*/


#include <iostream>
#include <string>
#include <iomanip> // Para usar setprecision y fixed
using namespace std;

// Paso 1: Definir la estructura Libro
struct Libro {
    string titulo;
    string autor;
    float precio;
};

int main() {
    // Paso 2: Crear un array dinámico con espacio para 2 libros
    Libro* libros = new Libro[2];

    // Paso 3: Pedir los datos de los 2 primeros libros
    cin.ignore(); // Limpiamos el buffer antes del primer getline

    for (int i = 0; i < 2; i++) {
        cout << "\nIntroduce los datos del libro " << i + 1 << ":\n";

        cout << "Título: ";
        getline(cin, libros[i].titulo);

        cout << "Autor: ";
        getline(cin, libros[i].autor);

        cout << "Precio: ";
        cin >> libros[i].precio;

        cin.ignore(); // Limpiamos el salto de línea para el siguiente getline
    }

    // Paso 4: Pedimos un nuevo libro adicional
    Libro nuevoLibro;

    cout << "\nIntroduce el nombre del tercer libro:\n";

    cout << "Título: ";
    getline(cin, nuevoLibro.titulo);

    cout << "Autor: ";
    getline(cin, nuevoLibro.autor);

    cout << "Precio: ";
    cin >> nuevoLibro.precio;

    // Paso 5: Crear un nuevo array dinámico con espacio para 3 libros
    Libro* nuevoArray = new Libro[3];

    // Paso 6: Copiar los 2 libros existentes al nuevo array
    for (int i = 0; i < 2; i++) {
        nuevoArray[i] = libros[i];
    }

    // Paso 7: Añadir el nuevo libro al final
    nuevoArray[2] = nuevoLibro;

    // Paso 8: Liberar la memoria del array original
    delete[] libros;

    // Paso 9: Redirigir el puntero original al nuevo array
    libros = nuevoArray;

    // Paso 10: Mostrar todos los libros guardados
    cout << "\n📚 Lista de libros registrada:\n";

    for (int i = 0; i < 3; i++) {
        cout << "\nLibro " << i + 1 << ":\n";
        cout << "Título: " << libros[i].titulo << endl;
        cout << "Autor: " << libros[i].autor << endl;
        cout << fixed << setprecision(2); // Mostrar precio con 2 decimales
        cout << "Precio: " << libros[i].precio << " €" << endl;
    }

    // Paso 11: Liberar la memoria final
    delete[] libros;

    return 0;
}
