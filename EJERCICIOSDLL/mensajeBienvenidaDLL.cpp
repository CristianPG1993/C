#include <windows.h>  // Incluye los tipos y funciones de la WinAPI

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID lpReserved)   // Punto de entrada que Windows llama automáticamente
{
    switch (ul_reason_for_call)  // Elegimos qué hacer según el motivo de llamada
    {
    case DLL_PROCESS_ATTACH:     // La DLL acaba de cargarse en un proceso
        MessageBoxA(NULL,
                    "Bienvenido. Esta DLL ha sido inyectada correctamente.",
                    "INYECCIÓN EXITOSA",
                    MB_OK | MB_ICONINFORMATION); // Mostramos un cuadro de bienvenida
        break;

    case DLL_PROCESS_DETACH:     // La DLL se va a descargar (ej: al cerrar el proceso)
        // Aquí podríamos liberar memoria, desactivar hooks, etc.
        break;

    case DLL_THREAD_ATTACH:      // Se ha creado un hilo nuevo en el proceso
    case DLL_THREAD_DETACH:      // Un hilo ha terminado
        // Por ahora, los ignoramos
        break;
    }
    return TRUE; // Confirmamos que la DLL se cargó correctamente
}