#include <iostream>
using namespace std;

int main(){
    int n;
    
    cout << "introduce un número: ";
    cin >> n;

    for (int i = 1; i <= 20; i++){
        cout << n << "X" << i << "=" << n*i << endl;
    }

}