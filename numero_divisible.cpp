#include <iostream>
using namespace std;


bool es_divisible(int a, int b){
    if ( a % b == 0){
       return true;
    }else {
       return false;
    }
}



int main(){

    int numero1;
    int numero2;


    cout << "Introduce el primer número: ";
    cin >> numero1;

    cout << "Introduce el segundo número: ";
    cin >> numero2;


    if(es_divisible(numero1, numero2)){

        cout << numero1 << " es divisible por " << numero2 << endl;

    }else{
        cout << numero1 << " no es divisible por " << numero2 << endl;
    }


    return 0;

}