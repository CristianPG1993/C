#include <iostream>
using namespace std;

int main(){
    int n;
    int numero_correcto = 0;

    do{
        cout << " Introduce el número correcto: ";
        cin >> n;
        if (n != numero_correcto) {
            cout << " Número incorrecto. Vuelve a intentarlo. " << endl;
        }
    } while (n != numero_correcto);

    cout << " Número correcto. Acceso permitido.";
    return 0;
    

    }
