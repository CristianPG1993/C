/*
=======================================================
🧪 EJERCICIO 4 - AÑADIR PERSONAS A UN ARRAY DINÁMICO
=======================================================

1. Crea una estructura llamada `Persona` que tenga:
   - nombre (string)
   - edad (int)

2. Crea un array dinámico con 2 personas.
3. Pide al usuario que introduzca nombre y edad de cada una.
4. Luego, pide una tercera persona (nombre y edad).
5. Crea un nuevo array dinámico con espacio para 3 personas.
6. Copia las 2 personas anteriores al nuevo array.
7. Añade la nueva persona al final.
8. Libera la memoria del array antiguo.
9. Redirige el puntero original al nuevo array.
10. Muestra todos los datos almacenados (nombre y edad de cada persona).

🎯 Objetivo: reforzar ampliación de memoria con estructuras.
*/

#include <iostream>
#include <string>
using namespace std;

// Paso 1: Declaramos la estructura Persona
struct Persona {
    string nombre;
    int edad;
};

int main() {
    // Paso 2: Creamos un array dinámico para 2 personas
    Persona* personas = new Persona[2];

    // Paso 3: Pedimos los datos (nombre y edad) de las 2 primeras personas
    cin.ignore(); // Limpiamos el buffer antes del primer getline

    for (int i = 0; i < 2; i++) {
        cout << "\nPersona " << i + 1 << ":" << endl;

        cout << "Introduce el nombre: ";
        getline(cin, personas[i].nombre);

        cout << "Introduce la edad: ";
        cin >> personas[i].edad;
        cin.ignore(); // Limpiamos el salto de línea para el próximo getline
    }

    // Paso 4: Pedimos una nueva persona
    Persona nuevaPersona;
    cout << "\nIntroduce el nombre de la tercera persona: ";
    getline(cin, nuevaPersona.nombre);

    cout << "Introduce su edad: ";
    cin >> nuevaPersona.edad;

    // Paso 5: Creamos un nuevo array dinámico con tamaño 3
    Persona* nuevoArray = new Persona[3];

    // Paso 6: Copiamos las 2 personas anteriores al nuevo array
    for (int i = 0; i < 2; i++) {
        nuevoArray[i] = personas[i];
    }

    // Paso 7: Añadimos la nueva persona en la última posición
    nuevoArray[2] = nuevaPersona;

    // Paso 8: Liberamos el array original y redirigimos el puntero
    delete[] personas;
    personas = nuevoArray;

    // Paso 9: Mostramos los datos de todas las personas
    cout << "\n📋 Lista completa de personas:\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nPersona " << i + 1 << ":\n";
        cout << "Nombre: " << personas[i].nombre << endl;
        cout << "Edad: " << personas[i].edad << " años" << endl;
    }

    // Paso 10: Liberamos la memoria final antes de salir
    delete[] personas;

    return 0;
}
