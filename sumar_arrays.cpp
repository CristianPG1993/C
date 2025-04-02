#include <iostream>
using namespace std;

int main(){
    int array1[5];
    int array2[5];
    int resultado[5];



cout << "Introduce los números del primer array: ";
for (int i = 0; i < 5; i++) {
    cout << "Introduce el número " << i + 1 << ": ";
    cin >> array1[i];
}

cout << "\nIntroduce los números del segundo array: ";
for (int i = 0; i < 5; i++) {
    cout << "Introduce el número " << i + 1 << ": ";
    cin >> array2[i];
}

for ( int i = 0; i < 5; i++){
    resultado[i] = array1[i] + array2[i];

}


cout << "Array resultante es; ";
for (int i = 0; i < 5; i++){
    cout << resultado[i] << " ";
}
cout << endl;

return 0;



}