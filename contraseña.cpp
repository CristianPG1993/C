#include <iostream>
using namespace std;

int main () {
    string clave;
    string clave_correcta = "hola1234";
    

    do {
        cout << "Ingrese la clave: ";
        cin >> clave;
        cout << "Clave incorrecta. Vuelva a intentarlo. " << endl;
    } while (clave != clave_correcta);

    cout << " Clave correcta. Acceso permitido." << endl;
    return 0;    

}