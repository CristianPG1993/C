#include <iostream>
using namespace std;

int main() {
    int i = 0;

    while (i <= 20) {
        if (i % 2 == 0) {
            cout << "El número " << i << " es par." << endl;
        }
        i++; // se incrementa siempre
    }

    return 0;
}
