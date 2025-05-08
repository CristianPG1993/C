/*
🧠 Ejercicio: Visualizar pisado de memoria en el stack

Objetivo:
- Declarar un array de 8 caracteres (`char clave[8]`)
- Declarar una variable entera justo después (`int accesoAutorizado = 0`)
- Leer más de 8 caracteres con `cin >> clave`
- Imprimir las direcciones de ambas variables con `&clave` y `&accesoAutorizado`
- Observar cómo cambia el valor de accesoAutorizado si se produce un buffer overflow

Paso adicional:
- Repetir usando `cin.getline(clave, 8)` para comprobar que el problema desaparece
*/


#include <iostream>
#include <string>
using namespace std;

int main(){

    string clave; // nos aseguramos que no se pisa la memoria utilizando std:: string
    int accesoAutorizado = 0;

    cout << "\nDirección memoria la variable clave: " << &clave << endl;
    cout << "\nDirección memoria la variable accesoAutorizado: " << &accesoAutorizado << endl;
    cout << "\nValor actual de accesoAutorizado: " << accesoAutorizado << endl;


    cout << "\nIntroduce la clave: ";
    getline(cin, clave);  // Solucionamos el pisado del valor de la memoria de accesoAutorizado utilizando getline

    cout << "\nDirección memoria la variable clave: " << &clave << endl;
    cout << "\nDirección memoria la variable accesoAutorizado: " << &accesoAutorizado << endl;
    cout << "\nValor actual de accesoAutorizado: " << accesoAutorizado << endl;


    return 0;

}