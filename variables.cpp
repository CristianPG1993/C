#include <iostream>
using namespace std;

int main(){
    int edad;
    cout << "Introduce tu edad: ";
    cin >> edad;

    if(edad >= 65){
        cout << "Eres adulto mayor." << endl;
    } if(edad >= 18 && edad < 65){
        cout << "Eres adulto joven." <<endl;
    } else (edad < 18);{
        cout << "Eres menor de edad." << endl;
    }

    return 0;

}