#include <windows.h>       // Librería principal de la API de Windows
#include <tlhelp32.h>      // Necesaria para tomar snapshots de procesos (enumeración)
#include <string>          // Para usar std::wstring
#include <iostream>        // Para mostrar mensajes en consola

// Función que recibe el nombre de un proceso y devuelve su PID
DWORD GetPIDByName(const std::wstring& processName)
{
    // Tomamos un snapshot de todos los procesos en ejecución
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    // Si falla, devolvemos 0 como indicador de error
    if (snapshot == INVALID_HANDLE_VALUE)
        return 0;

    // Estructura que usaremos para recorrer los procesos
    PROCESSENTRY32W entry;
    entry.dwSize = sizeof(PROCESSENTRY32W); // Es obligatorio establecer dwSize

    // Empezamos a recorrer la lista de procesos
    if (Process32FirstW(snapshot, &entry)) {
        do {
            // Comparamos el nombre del proceso actual con el nombre buscado
            if (wcscmp(entry.szExeFile, processName.c_str()) == 0) {
                CloseHandle(snapshot);                // Cerramos el snapshot
                return entry.th32ProcessID;          // Devolvemos el PID del proceso
            }
        } while (Process32NextW(snapshot, &entry));  // Continuamos con el siguiente proceso
    }

    // Si no lo encontramos, cerramos el snapshot y devolvemos 0
    CloseHandle(snapshot);
    return 0;
}

int main()
{
    // Nombre del proceso al que queremos inyectar la DLL
    std::wstring proceso = L"mspaint.exe";

    // Obtenemos el PID del proceso
    DWORD pid = GetPIDByName(proceso);

    // Si no se encuentra, mostramos error y salimos
    if (pid == 0)
    {
        std::wcout << L"No se encontró el proceso." << std::endl;
        return 1;
    }

    // Abrimos el proceso con los permisos necesarios para inyectar
    HANDLE hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_VM_OPERATION | PROCESS_VM_WRITE, FALSE, pid);
    if (hProcess == NULL)
    {
        std::wcout << L"No se pudo abrir el proceso." << std::endl;
        return 1;
    }

    // Ruta completa de la DLL que queremos inyectar
    const char* dllPath = "C:\\RUTA\\A\\TU\\mensaje.dll";

    // Reservamos memoria en el proceso remoto para guardar la ruta de la DLL
    LPVOID remoteMemory = VirtualAllocEx(
        hProcess,                      // Handle del proceso objetivo
        NULL,                          // Dirección base deseada (NULL = elige el sistema)
        strlen(dllPath) + 1,           // Tamaño a reservar (incluye '\0')
        MEM_COMMIT | MEM_RESERVE,      // Tipo de asignación
        PAGE_READWRITE                 // Permisos de lectura y escritura
    );

    // Escribimos la ruta de la DLL en la memoria reservada del proceso remoto
    WriteProcessMemory(
        hProcess,                      // Proceso de destino
        remoteMemory,                  // Dirección remota donde escribiremos
        dllPath,                       // Contenido a escribir (la ruta de la DLL)
        strlen(dllPath) + 1,           // Tamaño de los datos
        NULL                           // Podemos pasar NULL si no necesitamos saber cuántos bytes se escribieron
    );

    // Obtenemos el módulo kernel32.dll (donde se encuentra LoadLibraryA)
    HMODULE hKernel32 = GetModuleHandleA("kernel32.dll");

    // Obtenemos la dirección de LoadLibraryA en la memoria local
    LPVOID loadLibraryAddr = (LPVOID)GetProcAddress(hKernel32, "LoadLibraryA");

    // Creamos un hilo remoto en el proceso destino que ejecutará LoadLibraryA con nuestra ruta como argumento
    HANDLE hThread = CreateRemoteThread(
        hProcess,                           // Proceso remoto
        NULL,                               // Seguridad (NULL por defecto)
        0,                                  // Tamaño del stack (0 = por defecto)
        (LPTHREAD_START_ROUTINE)loadLibraryAddr, // Función que se va a ejecutar
        remoteMemory,                       // Argumento para la función (la ruta de la DLL)
        0,                                  // Flags de creación (0 = ejecutar inmediatamente)
        NULL                                // ID del hilo (no lo necesitamos)
    );

    // Comprobamos si el hilo se creó correctamente
    if (hThread == NULL)
    {
        std::wcout << L"No se pudo crear el hilo remoto." << std::endl;
    }
    else
    {
        std::wcout << L"¡DLL inyectada con éxito!" << std::endl;
    }

    // Cerramos los handles para liberar recursos
    CloseHandle(hThread);
    CloseHandle(hProcess);

    return 0;
}
