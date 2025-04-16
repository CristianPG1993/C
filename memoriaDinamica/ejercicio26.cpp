/*
==========================================================================
⚽ EJERCICIO 9 - GESTIÓN DE JUGADORES Y SUS PARTIDOS (ESTRUCTURA ANIDADA)
==========================================================================

1. Crea una estructura `Partido` con:
   - rival (string)
   - golesMarcados (int)

2. Crea una estructura `Jugador` con:
   - nombre (string)
   - equipo (string)
   - un array dinámico de `Partido`
   - un entero que indique cuántos partidos ha jugado

3. Pide cuántos jugadores se van a registrar.
4. Para cada jugador, pide:
   - nombre
   - equipo
   - número de partidos
   - y para cada partido, el rival y los goles marcados

5. Guarda todo en un array dinámico de `Jugador`.
6. Al final, muestra un informe con todos los datos.

🎯 Objetivo: seguir reforzando estructuras anidadas y arrays dinámicos
*/


#include <iostream>
#include <string>
using namespace std;

// Paso 1: Estructura Partido (anidada dentro de Jugador)
struct Partido {
    string rival;
    int golesMarcados;
};

// Paso 2: Estructura Jugador con array dinámico de partidos
struct Jugador {
    string nombre;
    string equipo;
    Partido* partidos;       // Array dinámico de partidos
    int contadorPartidos;    // Número de partidos jugados
};

int main() {
    int cantidad;

    // Paso 3: Pedimos cuántos jugadores se registrarán
    cout << "¿Cuántos jugadores desea ingresar? " << endl;
    cin >> cantidad;

    // Creamos array dinámico de jugadores
    Jugador* jugadores = new Jugador[cantidad];
    cin.ignore(); // Limpiamos buffer antes del primer getline

    // Paso 4: Recorremos cada jugador y pedimos sus datos
    for (int i = 0; i < cantidad; i++) {
        cout << "\nJugador " << i + 1 << ":\n";

        cout << "Nombre: ";
        getline(cin, jugadores[i].nombre);

        cout << "Equipo: ";
        getline(cin, jugadores[i].equipo);

        cout << "¿Cuántos partidos deseas añadir?: ";
        cin >> jugadores[i].contadorPartidos;

        // Paso 5: Reservamos memoria para los partidos
        jugadores[i].partidos = new Partido[jugadores[i].contadorPartidos];
        cin.ignore();

        // Paso 6: Pedimos los datos de cada partido
        for (int j = 0; j < jugadores[i].contadorPartidos; j++) {
            cout << "\nPartido " << j + 1 << ":\n";

            cout << "Rival: ";
            getline(cin, jugadores[i].partidos[j].rival);

            cout << "Goles marcados: ";
            cin >> jugadores[i].partidos[j].golesMarcados;
            cin.ignore(); // Para el siguiente getline
        }
    }

    // Paso 7: Mostrar el informe final
    cout << "\n📄 INFORME DE JUGADORES:\n";

    for (int i = 0; i < cantidad; i++) {
        cout << "\n----------------------------------------\n";
        cout << "Jugador " << i + 1 << ":\n";
        cout << "Nombre: " << jugadores[i].nombre << endl;
        cout << "Equipo: " << jugadores[i].equipo << endl;

        cout << jugadores[i].nombre << " ha jugado contra:\n";

        for (int j = 0; j < jugadores[i].contadorPartidos; j++) {
            cout << "\n  Rival " << j + 1 << ":\n";
            cout << "  Equipo rival: " << jugadores[i].partidos[j].rival << endl;
            cout << "  Goles marcados: " << jugadores[i].partidos[j].golesMarcados << " goles.\n";
        }
    }

    // Paso 8: Liberar la memoria dinámica
    for (int i = 0; i < cantidad; i++) {
        delete[] jugadores[i].partidos;
    }

    delete[] jugadores;
    return 0;
}


