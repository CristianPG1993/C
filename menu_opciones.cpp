#include <iostream>
using namespace std;

int main() {
    int opcion; // Variable para la opción del usuario

    do {
        //Mostrar el menú de opciones
        cout << " \n MENU DE OPCIONES " << endl;
        cout << "1. Saludar" << endl;
        cout << "2. Tabla de multiplicar" << endl;
        cout << "3. Salir" << endl;
        cout << "Ingresar una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: // Opción 1: Saludar
                cout << "👋 Hola, bienvenido al programa!" << endl;
                break;

            case 2: { // Opción 2: Tabla de multiplicar
                int num;
                cout << "Ingrese un número: ";
                cin >> num;
                
                cout << "Tabla del " << num << ":" << endl;
                for (int i = 1; i <= 10; i++) {
                    cout << num << " x " << i << " = " << num * i << endl;
                }
                break;
            }

            case 3: // Opción 3: Salir
                cout << "👋 Saliendo del programa..." << endl;
                break;

            default: // Si el usuario ingresa una opción no válida
                cout << "⚠️ Opción no válida. Intente de nuevo." << endl;
        }

    } while (opcion != 3); // Repite el menú hasta que el usuario elija "3"

    return 0;
}
