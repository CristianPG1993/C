#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

int main() {
    const int bufferSize = 64;
    unsigned char buffer[bufferSize];

    // Simular dirección base del stack (alta)
    unsigned int topAddress = 0xBFFFF0; // dirección más alta simulada

    // Paso 1: NOP sled
    memset(buffer, 0x90, bufferSize); // llenar todo con \x90

    // Paso 2: shellcode simulado
    const char* shellcode = "SHC0"; // solo como marcador visual
    memcpy(buffer + 32, shellcode, strlen(shellcode));

    // Paso 3: sobrescribir RET (últimos 4 bytes)
    unsigned int retAddr = 0xBFFFD8; // dirección donde empieza el buffer
    memcpy(buffer + bufferSize - 4, &retAddr, 4);

    // Mostrar buffer simulando pila (crece hacia abajo)
    cout << "Simulación del stack (dirección ↓, contenido byte a byte):\n";
    for (int i = bufferSize - 1; i >= 0; --i) {
        unsigned int addr = topAddress - (bufferSize - 1 - i);
        cout << hex << setw(8) << setfill('0') << addr << ": "
             << setw(2) << (int)buffer[i] << "\n";
    }

    cout << "\nResumen:\n";
    cout << "- Shellcode simulado \"SHC0\" en [32–35] (≈ dirección 0xBFFFD8)\n";
    cout << "- Dirección RET (0xBFFFD8) sobrescrita en [60–63]\n";
    cout << "- NOP sled antes del shellcode\n";

    return 0;
}
