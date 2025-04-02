#include <iostream>
using namespace std;

int main(){
    int n;
    int suma_digitos = 0;

    cout << " Introduce un número: ";
    cin >> n;


    while (n > 0) {  // ✅ Se ejecuta mientras haya dígitos en n
    suma_digitos += n % 10; // ✅ Extrae el último dígito y lo suma
    n = n / 10; // ✅ Elimina el último dígito de n
}
    
    cout << "La suma de los dígitos es: " << suma_digitos << "." << endl;
    return 0;


}