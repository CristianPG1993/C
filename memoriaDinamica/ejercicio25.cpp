/*
==========================================================================
🎨 EJERCICIO 8 - GESTIÓN DE ARTISTAS Y SUS OBRAS (ESTRUCTURA ANIDADA)
==========================================================================

1. Crea una estructura `Obra` con:
   - título (string)
   - añoCreacion (int)

2. Crea una estructura `Artista` con:
   - nombre (string)
   - país (string)
   - un array dinámico de `Obra`
   - un entero que indique cuántas obras tiene

3. Pide al usuario cuántos artistas desea registrar.
4. Para cada artista, pide:
   - nombre
   - país
   - cuántas obras tiene
   - para cada obra, pide el título y el año de creación
5. Guarda toda la información en un array dinámico de `Artista`.
6. Muestra toda la información registrada (nombre, país y todas sus obras).

🎯 Objetivo: reforzar estructuras anidadas, arrays dinámicos y lectura mixta con `getline()` y `cin`.
*/

#include <iostream>
#include <string>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

// Paso 1: Estructura Obra (anidada dentro de Artista)
struct Obra {
    string titulo;
    int anioCreacion;
};

// Paso 2: Estructura Artista con array dinámico de obras
struct Artista {
    string nombre;
    string pais;
    Obra* obras;         // Puntero dinámico a array de obras
    int cantidadObras;   // Número de obras
};

int main() {
    int cantidad;

    // Paso 3: Pedimos cuántos artistas se van a registrar
    cout << "¿Cuántos artistas vas a introducir? ";
    cin >> cantidad;

    // Creamos array dinámico de artistas
    Artista* artistas = new Artista[cantidad];
    cin.ignore(); // Limpiamos buffer antes del primer getline

    // Paso 4: Recorremos cada artista y pedimos datos
    for (int i = 0; i < cantidad; i++) {
        cout << "\nArtista " << i + 1 << ":\n";

        cout << "Nombre: ";
        getline(cin, artistas[i].nombre);

        cout << "País: ";
        getline(cin, artistas[i].pais);

        cout << "¿Cuántas obras deseas introducir?: ";
        cin >> artistas[i].cantidadObras;

        // Paso 5: Reservamos memoria para sus obras
        artistas[i].obras = new Obra[artistas[i].cantidadObras];
        cin.ignore();

        if (artistas[i].cantidadObras > 0) {
            // Pedimos los datos de cada obra
            for (int j = 0; j < artistas[i].cantidadObras; j++) {
                cout << "\nObra " << j + 1 << ":\n";

                cout << "Título de la obra: ";
                getline(cin, artistas[i].obras[j].titulo);

                cout << "Año de creación: ";
                cin >> artistas[i].obras[j].anioCreacion;
                cin.ignore();
            }
        } else {
            cout << "\nTienes que introducir al menos una obra.\n";
        }
    }

    // Paso 6: Mostrar la información registrada
    cout << "\n📄 INFORME DE ARTISTAS:\n";

    for (int i = 0; i < cantidad; i++) {
        cout << "\n----------------------------------------\n";
        cout << "Artista " << i + 1 << ":\n";
        cout << "Nombre: " << artistas[i].nombre << endl;
        cout << "País: " << artistas[i].pais << endl;
        cout << "Obras:\n";

        for (int j = 0; j < artistas[i].cantidadObras; j++) {
            cout << " - Título: " << artistas[i].obras[j].titulo << endl;
            cout << "   Año: " << artistas[i].obras[j].anioCreacion << endl;
        }
    }

    // Paso 7: Liberar la memoria dinámica
    for (int i = 0; i < cantidad; i++) {
        delete[] artistas[i].obras; // Liberar array de obras de cada artista
    }
    delete[] artistas; // Liberar array de artistas

    return 0;
}

