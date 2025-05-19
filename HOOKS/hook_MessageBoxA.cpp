#include <windows.h>
#include <iostream>
#include <MinHook.h>

// Puntero al original MessageBoxA
typedef int (WINAPI* MessageBoxA_t)(HWND, LPCSTR, LPCSTR, UINT);
MessageBoxA_t originalMessageBoxA = NULL;

// Hook: reemplaza a MessageBoxA
int WINAPI hookedMessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType) {
    std::cout << "[HOOK] MessageBox interceptado!" << std::endl;
    std::cout << "Texto original: " << lpText << std::endl;

    // Podemos modificar el mensaje:
    LPCSTR nuevoTexto = "Este mensaje fue interceptado.";
    LPCSTR nuevoTitulo = "HOOK ACTIVADO";

    // Llamamos a la función original
    return originalMessageBoxA(hWnd, nuevoTexto, nuevoTitulo, uType);
}

int main() {
    // Inicializa MinHook
    if (MH_Initialize() != MH_OK) {
        std::cerr << "Error al inicializar MinHook" << std::endl;
        return 1;
    }

    // Crea el hook
    if (MH_CreateHook(reinterpret_cast<LPVOID>(&MessageBoxA), 
                    reinterpret_cast<LPVOID>(&hookedMessageBoxA), 
                    reinterpret_cast<LPVOID*>(&originalMessageBoxA)) != MH_OK){
                        
        std::cerr << "Error al crear el hook" << std::endl;
        return 1;
    }

    // Habilita el hook
    if (MH_EnableHook(reinterpret_cast<LPVOID>(&MessageBoxA)) != MH_OK){
        std::cerr << "Error al habilitar el hook" << std::endl;
        return 1;
    }

    // Prueba el hook
    MessageBoxA(NULL, "Texto original", "Título original", MB_OK);

    // Limpieza
    MH_DisableHook(reinterpret_cast<LPVOID>(&MessageBoxA));
    MH_Uninitialize();

    return 0;
}
