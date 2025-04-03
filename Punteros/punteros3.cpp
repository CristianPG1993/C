/*
Crea una función llamada intercambiar que reciba dos punteros a enteros 
y que intercambie sus valores.

Luego, en el main, declara dos variables con valores diferentes, 
muestra sus valores antes y después de llamar a la función.
*/

#include <iostream>
using namespace std;



void intercambiar(int* a, int* b){

    int temp = *a;
    *a = *b;
    *b = temp;

}


int main(){

    int x = 10;
    int y = 20;

    cout << "El valor de X es: " << x << endl;
    cout << "El valor de Y es: " << y << endl;
    
    
    intercambiar(&x, &y);

    cout << "El valor de X es: " << x << endl;
    cout << "El valor de Y es: " << y << endl;

    return 0;
}