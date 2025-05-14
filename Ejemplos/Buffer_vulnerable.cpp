/*
 * Simulación de exploit con NOP sled y sobrescritura de RET
 * ---------------------------------------------------------
 * Este programa no ejecuta ningún código malicioso.
 * Solo muestra cómo un atacante podría construir un payload
 * para sobrescribir un buffer vulnerable en el stack.
 */

#include <iostream>      // Para imprimir por consola
#include <iomanip>       // Para imprimir en formato hexadecimal con setw, setfill
#include <cstring>       // Para usar funciones como memset() y memcpy()

using namespace std;

int main() {
    const int bufferSize = 64;  // 🧱 Tamaño total del buffer simulado (64 bytes)
    unsigned char buffer[bufferSize];  
    // 🔹 Usamos 'unsigned char' para representar datos binarios byte a byte

    // Paso 1: rellenamos el buffer con NOPs (\x90)
    memset(buffer, 0x90, bufferSize); 
    // 🔸 memset llena los 64 bytes del buffer con el valor 0x90 (NOP)
    // Esto simula el "NOP sled": una pista de aterrizaje para que el salto al shellcode no tenga que ser exacto

    // Paso 2: insertar shellcode falso (simulado como texto)
    const char* shellcode = "SHC0"; 
    // 🔹 Aquí usamos una cadena de texto como si fuera un shellcode real. 
    // En un exploit real, esto serían bytes de código ensamblador

    int shellcodeLen = strlen(shellcode);  // Obtenemos su longitud: 4 bytes

    // Insertamos el shellcode a partir del byte 32 del buffer
    memcpy(buffer + 32, shellcode, shellcodeLen);
    // 🔸 Copiamos los 4 bytes de "SHC0" a las posiciones [32] a [35] del buffer

    // Paso 3: insertar dirección RET falsa (que apunta al shellcode)
    unsigned int retAddr = 0xBFFFF020;
    // 🔹 Esta sería la dirección en la que empieza el shellcode en memoria real (simulado)

    // Copiamos esos 4 bytes al final del buffer (últimos 4 bytes: [60–63])
    memcpy(buffer + bufferSize - 4, &retAddr, 4);
    // 🔸 Usamos &retAddr para copiar los bytes directamente en formato little-endian

    // Mostrar el contenido del buffer en formato hexadecimal
    cout << "Contenido del buffer simulado (hex):\n";

    // Imprime 8 bytes por línea
    for (int i = 0; i < bufferSize; ++i) {
        if (i % 8 == 0) cout << setw(4) << i << ": ";
        // 🔸 Imprime el índice de inicio de la línea (0, 8, 16, ...)

        cout << hex << setfill('0') << setw(2) << (int)buffer[i] << " ";
        // 🔸 Imprime el byte actual en formato hexadecimal con dos dígitos

        if (i % 8 == 7) cout << endl;
        // 🔸 Salto de línea cada 8 bytes
    }

    // Mostrar resumen textual del contenido
    cout << "\nResumen:\n";
    cout << "- NOP sled: 0x90 desde [0] hasta [31]\n";
    cout << "- Shellcode simulado (\"SHC0\"): desde [32] a [35]\n";
    cout << "- Dirección RET sobrescrita con 0xBFFFF020 en [60-63]\n";
    // 🔸 Explicación en texto del contenido importante del buffer

    return 0;
}
