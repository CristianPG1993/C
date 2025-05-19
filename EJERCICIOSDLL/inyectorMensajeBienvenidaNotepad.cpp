#include <windows.h>           // Funciones y tipos de Windows
#include <tlhelp32.h>          // Para tomar snapshots de procesos
#include <iostream>            // Para imprimir en consola
#include <string>              // Para manejar cadenas de texto

// ------------------------------------
// Función para obtener el PID de un proceso por nombre
// ------------------------------------
DWORD ObtenerPID(const wchar_t* nombreProceso) {
    DWORD pid = 0;

    // Crear snapshot de todos los procesos en ejecución
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE)
        return 0;

    // Estructura para recorrer los procesos
    PROCESSENTRY32W entry;
    entry.dwSize = sizeof(entry);

    // Recorrer todos los procesos del snapshot
    if (Process32FirstW(snapshot, &entry)) {
        do {
            if (wcscmp(entry.szExeFile, nombreProceso) == 0) {
                pid = entry.th32ProcessID;
                break;
            }
        } while (Process32NextW(snapshot, &entry));
    }

    CloseHandle(snapshot);
    return pid;
}

// ------------------------------------
// Función principal
// ------------------------------------
int main() {
    const wchar_t* nombre = L"notepad.exe"; // Nombre del proceso destino
    DWORD pid = ObtenerPID(nombre);         // Obtener PID del proceso

    // Validar si se encontró
    if (pid == 0) {
        std::wcerr << L"[ERROR] No se encontró el proceso: " << nombre << std::endl;
        return 1;
    }

    std::wcout << L"[OK] PID de " << nombre << L": " << pid << std::endl;
    std::cout << "[INFO] Intentando abrir el proceso remoto..." << std::endl;

    // Abrir el proceso con todos los permisos
    HANDLE hProceso = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    if (hProceso == NULL) {
        std::cerr << "[ERROR] No se pudo abrir el proceso remoto." << std::endl;
        return 1;
    }

    std::cout << "[OK] Proceso abierto correctamente." << std::endl;
    std::cout << "[INFO] Reservando memoria remota..." << std::endl;

    // Ruta del DLL a inyectar (puedes usar ruta absoluta si falla)
    const char* rutaDLL = "MensajeBienvenidaDLL\\MensajeBienvenidaDLL.dll";

    // Reservar memoria en el proceso remoto
    LPVOID direccionRemota = VirtualAllocEx(
        hProceso,
        NULL,
        strlen(rutaDLL) + 1,             // Reservar el tamaño de la ruta + terminador '\0'
        MEM_COMMIT | MEM_RESERVE,        // Reservar y comprometer memoria
        PAGE_READWRITE                   // Permisos de lectura y escritura
    );

    if (direccionRemota == NULL) {
        std::cerr << "[ERROR] No se pudo reservar memoria remota." << std::endl;
        CloseHandle(hProceso);
        return 1;
    }

    std::cout << "[OK] Memoria remota reservada en: " << direccionRemota << std::endl;
    std::cout << "[INFO] Escribiendo ruta del DLL en la memoria remota..." << std::endl;

    // Escribir la ruta del DLL en la memoria del proceso remoto
    BOOL escrito = WriteProcessMemory(
        hProceso,
        direccionRemota,
        rutaDLL,
        strlen(rutaDLL) + 1,
        NULL
    );

    if (!escrito) {
        std::cerr << "[ERROR] No se pudo escribir en la memoria remota." << std::endl;
        CloseHandle(hProceso);
        return 1;
    }

    std::cout << "[OK] Se ha inyectado correctamente la ruta DLL en memoria remota." << std::endl;
    std::cout << "[INFO] Creando hilo remoto con LoadLibraryA..." << std::endl;

    // Crear un hilo remoto que ejecuta LoadLibraryA con la ruta del DLL
    HANDLE hiloRemoto = CreateRemoteThread(
        hProceso,
        NULL,
        0,
        (LPTHREAD_START_ROUTINE)GetProcAddress(        // Dirección de LoadLibraryA
            GetModuleHandleA("kernel32.dll"),
            "LoadLibraryA"
        ),
        direccionRemota,                               // Argumento: ruta del DLL
        0,
        NULL
    );

    if (hiloRemoto == NULL) {
        std::cerr << "[ERROR] No se pudo crear el hilo remoto." << std::endl;
        CloseHandle(hProceso);
        return 1;
    }

    std::cout << "[OK] Hilo remoto creado. DLL inyectada correctamente." << std::endl;

    // Limpiar: cerrar handles abiertos
    CloseHandle(hiloRemoto);
    CloseHandle(hProceso);

    return 0;
}
