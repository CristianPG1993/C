/*
🛠️ Herramienta: Simulador de Fuerza Bruta Numérica

Descripción:
Simula cómo un atacante encontraría una contraseña numérica de 4 dígitos
mediante un ataque de fuerza bruta. El programa genera e imprime cada intento
desde 0000 hasta 9999 hasta acertar con la contraseña objetivo.

Objetivo educativo:
Visualizar el tiempo y pasos que puede tomar una técnica de ataque de fuerza bruta,
y fomentar el uso de contraseñas más complejas.

Funcionamiento:
- La contraseña objetivo se almacena en una variable (hardcoded).
- Se generan intentos numéricos de 0000 a 9999.
- Se imprimen los intentos.
- Al acertar, se muestra el número de intentos usados.

Extensiones posibles:
- Comparar tiempos con y sin impresión
- Generar contraseña aleatoria
- Añadir retardo artificial para simular protección

*/


#include <iostream>      // Librería estándar de entrada/salida
#include <iomanip>       // Para usar setw y setfill
using namespace std;

// Función que simula un ataque de fuerza bruta sobre una clave de 4 dígitos
void contraseñaEncontradaPorFuerzaBruta(int clave) {
    int contadorIntentos = 0; // Contador de intentos realizados

    // Bucle que prueba todas las combinaciones posibles de 0000 a 9999
    for (int intento = 0; intento <= 9999; intento++) {
        // Imprimir el intento con 4 dígitos, rellenando con ceros si es necesario
        cout << "\nIntento " << setw(4) << setfill('0') << intento << ". ";
        contadorIntentos++;

        // Comparar el intento actual con la clave
        if (intento != clave) {
            cout << "Intento de fuerza bruta denegado.";
        } else {
            // Si la clave es encontrada, imprimir éxito y salir del bucle
            cout << "✅ Clave conseguida por fuerza bruta con éxito.";
            break;
        }
    }

    // Mostrar estadísticas finales
    cout << "\n\n🔓 Clave encontrada: " << setw(4) << setfill('0') << clave << endl;
    cout << "📊 Intentos realizados: " << contadorIntentos << endl;
}

// Función principal
int main() {
    int clave;

    // Solicitar al usuario que introduzca una clave objetivo
    cout << "\nIntroduce la clave (0000 - 9999): ";
    cin >> clave;

    // Ejecutar la simulación de fuerza bruta
    contraseñaEncontradaPorFuerzaBruta(clave);

    return 0;
}