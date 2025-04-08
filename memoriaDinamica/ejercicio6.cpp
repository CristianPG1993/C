/*
    EJERCICIO: Clasificación de números según su paridad y promedio

    Descripción:
    Crea un programa que permita:

    1. Introducir N números en un array dinámico.
    2. Mostrar todos los números introducidos.
    3. Calcular la media de todos los números.
    4. Separar y mostrar los números pares.
    5. Separar y mostrar los números impares.
    6. Mostrar cuántos números son mayores que la media.

    Requisitos:
    - Usar funciones para cada tarea.
    - Usar memoria dinámica con `new` y liberar con `delete[]`.
*/


#include <iostream>
using namespace std;

void cargarDatos(int* arr, int tamano){

    for (int i = 0; i < tamano; i++){

        cout << "Introduce el numero " << i + 1 << ": ";
        cin >> arr[i]; 
    }
}

void mostrarArray(int* arr, int tamano){


    cout << "Los valores introducidos son: ";
    for (int i = 0; i < tamano; i++){
        cout << arr[i]<< " ";

    }cout << endl;
}

float calcularMedia(int* arr, int tamano){

    int suma = 0;
    
    for (int i = 0; i < tamano; i++){

        suma+= arr[i];

        }

    float media = float(suma) / tamano;

    return media;

    
}

void mostrarPares(int* arr, int tamano){
    int contadorPares = 0;

    for (int i = 0; i < tamano; i++){

        if (arr[i] % 2 == 0){

            contadorPares ++;
        }
    }
    cout << "Existen " << contadorPares << " numeros pares." << endl;


}
 void mostrarImpares(int* arr, int tamano){

    int contadorImpares = 0;
    
    for (int i = 0; i < tamano; i++){

        if(arr[i] % 2 != 0){

            contadorImpares++;
        }
    }

    cout << "Existen " << contadorImpares << " numeros impares." << endl;


 }

 void mayoresQueMedia(int* arr, int tamano, float media){

    cout << "Los valores por encima de la media (" << media << ") son: ";

    bool alguno = false; // Para saber si se encontró alguno

    for (int i = 0; i < tamano; i++) {
        if (arr[i] > media) {
            cout << arr[i] << " ";
            alguno = true;
        }
    }

    if (!alguno) {
        cout << "Ninguno";
    }

    cout << endl;

 }

 int main(){

    int cantidad;

    cout <<"¿Cuantos números deseas introducir?";
    cin >> cantidad;

    int* numeros = new int[cantidad];

    cargarDatos(numeros, cantidad);

    mostrarArray(numeros, cantidad);
    
    
    float media = calcularMedia(numeros, cantidad);
    mostrarPares(numeros, cantidad);
    mostrarImpares(numeros, cantidad);
    mayoresQueMedia(numeros, cantidad, media);


    delete [] numeros;
    return 0;



 }
