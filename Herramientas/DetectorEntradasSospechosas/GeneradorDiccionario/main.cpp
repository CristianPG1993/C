/*
💣 Herramienta: Generador de Diccionario desde Lista Base

Objetivo:
Simular un generador de contraseñas basado en palabras base (ej. nombres, marcas, usuarios)
y patrones comunes usados por usuarios reales en contraseñas.

Funcionamiento:
1. Se define una lista de palabras base: nombres, marcas, apodos...
2. Se define una lista de sufijos comunes: 123, !, 2024, 01, etc.
3. El programa genera combinaciones palabra + sufijo
4. Opcional: palabra sola y sufijo al inicio también

Ejemplo de salida:
- maria123
- maria2024
- neven!
- !admin
- duman01

Objetivo educativo:
Mostrar cómo se generan diccionarios personalizados para ataques realistas en C++.

*/


#include <iostream>
#include <string>
#include <fstream>
using namespace std;


int main(){

    string palabrasBase[] = {"admin", "user", "juan", "maria"};
    string sufijos[] = {"123", "2024", "!", "01", "@", "_"};
    ofstream archivo("diccionario.txt");

    int nPalabras = sizeof(palabrasBase)/sizeof(palabrasBase[0]);
    int nSufijos = sizeof(sufijos)/sizeof(sufijos[0]);


    for (int i = 0; i < nPalabras; i++){
        for (int j= 0; j < nSufijos; j++){

        archivo << palabrasBase[i] + sufijos[j] << endl;
        archivo << sufijos[j] + palabrasBase[i] << endl;
        }
    }

    archivo.close();



}