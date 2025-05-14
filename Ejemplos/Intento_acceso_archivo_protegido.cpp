/*
-------------------------------------------------------------------------------------
📝 ENUNCIADO:

Este programa en C++ intenta abrir un archivo protegido del sistema Windows:
`C:\Windows\System32\config\SAM`.

El archivo SAM contiene los hashes de contraseñas de los usuarios locales. Solo puede
ser accedido por procesos con privilegios elevados, como SYSTEM o servicios especiales.

El objetivo del programa es demostrar cómo el kernel de Windows aplica control de acceso.
Utiliza la función `CreateFileW` (versión Unicode) para intentar abrir el archivo, y luego
recupera el código de error con `GetLastError`.

Se muestra un mensaje claro indicando si el acceso fue denegado, si el archivo no existe,
o si hubo otro error. En esta versión, se usa `std::cout` en lugar de `std::wcout` para 
garantizar que la consola imprima correctamente el resultado sin necesidad de configuraciones
adicionales de codificación.

-------------------------------------------------------------------------------------
*/

#include <windows.h>    // Cabecera principal para funciones de la API de Windows
#include <iostream>     // Para imprimir por consola (salida estándar)

int main() {
    // Intentamos abrir el archivo SAM (protegido por el sistema) usando CreateFileW
    HANDLE hFile = CreateFileW(
        L"C:\\Windows\\System32\\config\\SAM",  // Ruta del archivo (formato wide string para Unicode)
        GENERIC_READ,                           // Queremos solo leer el archivo
        0, NULL,                                 // Sin compartir, sin seguridad personalizada
        OPEN_EXISTING,                          // Solo abre si ya existe (no lo crea)
        FILE_ATTRIBUTE_NORMAL, NULL);           // Atributos normales, sin herencia

    // Comprobamos si la apertura fue fallida
    if (hFile == INVALID_HANDLE_VALUE) {
        // Obtenemos el código de error del sistema
        DWORD errorCode = GetLastError();

        // Siempre mostramos el código de error para análisis
        std::cout << "[X] Error al abrir el archivo. Código: " << errorCode << std::endl;

        // Interpretamos el error si es uno de los más comunes
        if (errorCode == ERROR_ACCESS_DENIED) {
            std::cout << "→ Motivo: acceso denegado (no tienes permisos suficientes)." << std::endl;
        } else if (errorCode == ERROR_FILE_NOT_FOUND) {
            std::cout << "→ Motivo: el archivo no existe en la ruta especificada." << std::endl;
        } else {
            std::cout << "→ Motivo: otro error del sistema o ruta incorrecta." << std::endl;
        }
    } else {
        // Si el archivo se abrió correctamente (poco probable con SAM), lo indicamos
        std::cout << "[✓] Archivo abierto correctamente." << std::endl;

        // Cerramos el manejador para liberar el recurso
        CloseHandle(hFile);
    }

    return 0; // Fin del programa
}
