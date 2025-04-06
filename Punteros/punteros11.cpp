/*
1. Crea una estructura llamada EstadisticasNotas con los campos:
   - float maxNota
   - float minNota
   - float promedio
   - int aprobados

2. Crea una función analizarNotas que reciba dos punteros (inicio y fin)
   y devuelva la estructura con los resultados.

3. En el main:
   - Pide al usuario que introduzca 5 notas
   - Guarda las notas en un array
   - Llama a la función y muestra los resultados
*/

#include <iostream>
using namespace std;


struct EstadisticaNotas {

    float maxNota;
    float minNota;
    float promedio;
    int aprobados;

};

EstadisticaNotas analizarNotas (float* inicio, float* fin){

    EstadisticaNotas resultado;
    
    resultado.maxNota = *inicio;
    resultado.minNota = *inicio;
    resultado.promedio = *inicio;
    resultado.aprobados = 0;

    float* actual = inicio;
    float suma = 0;
    int contador = 0;

    while(actual <= fin){

        if(*actual > resultado.maxNota){

            resultado.maxNota = *actual;


        }
        if(*actual < resultado.minNota){

            resultado.minNota = *actual;

        }if (*actual >= 5){

            resultado.aprobados++;

        }

        suma += *actual;
        contador++;

        actual++;

    }

    

    resultado.promedio = suma / contador;

    return resultado;
}


int main(){

    float notas[5]{};
    float* ptr = notas;

    
    for (int i = 0; i < 5; i++){

        cout << "Introduce una nota: ";
        cin >> notas[i];
        
    }


    EstadisticaNotas resultado = analizarNotas(ptr, ptr + 4);


    cout << "Las notas son: ";
    for (int i = 0; i < 5; i++){
        cout << *(ptr + i) << " ";

    }cout << endl;

    cout << "La nota más alta es: " << resultado.maxNota << endl;
    cout << "La nota más baja es: " << resultado.minNota << endl;
    cout << "La media de las notas es: " << resultado.promedio << endl;
    cout << "Asignaturas aprobadas: " << resultado.aprobados << endl;

    return 0;
}