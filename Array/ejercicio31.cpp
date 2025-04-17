/*
===============================================
📚 ENUNCIADO - GESTIÓN DE BIBLIOTECAS Y LIBROS
===============================================

Crea un programa en C++ que permita gestionar varias bibliotecas y sus libros asociados.

Cada biblioteca debe contener la siguiente información:
- Nombre (string)
- Ciudad (string)
- Un array dinámico de libros

Cada libro registrado debe tener:
- Título (string)
- Autor (string)
- Año de publicación (int)

El programa debe permitir al usuario:

1. Registrar un número inicial de bibliotecas y sus libros.
2. Añadir una nueva biblioteca si el usuario así lo desea (con sus libros correspondientes).
3. Mostrar al final un informe de todas las bibliotecas con sus respectivos libros.
4. Liberar correctamente la memoria utilizada (tanto para los libros como para las bibliotecas).

Nota: Utiliza estructuras anidadas y arrays dinámicos para representar las bibliotecas y sus libros.
*/


#include <iostream>     // Entrada y salida estándar
#include <string>       // Para poder usar strings
using namespace std;

// Estructura que representa un libro
struct Libro
{
    string titulo;
    string autor;
    int anioPublicacion;
};

// Estructura que representa una biblioteca
struct Biblioteca
{
    string nombre;
    string ciudad;
    Libro* libros;            // Array dinámico de libros
    int cantidadLibros;       // Cantidad de libros en la biblioteca
};

int main() {

    int cantidad;

    // Preguntamos al usuario cuántas bibliotecas desea introducir
    cout << "\n¿Cuantas bibliotecas desea introducir? " << endl;
    cin >> cantidad;

    int bibliotecasTotales = cantidad; // Variable para contar cuántas hay en total (inicialmente las que puso)

    Biblioteca* bibliotecas = new Biblioteca[cantidad]; // Creamos el array dinámico de bibliotecas
    cin.ignore(); // Limpiamos el buffer

    // Recorremos cada biblioteca para pedir los datos
    for (int i = 0; i < cantidad; i++) {
        cout << "\nBiblioteca " << i + 1 << ": " << endl;

        cout << "Titulo: ";
        getline(cin, bibliotecas[i].nombre);

        cout << "Ciudad: ";
        getline(cin, bibliotecas[i].ciudad);

        cout << "¿Cuantos libros deseas introducir?: ";
        cin >> bibliotecas[i].cantidadLibros;
        cin.ignore();

        // Creamos el array dinámico de libros
        bibliotecas[i].libros = new Libro[bibliotecas[i].cantidadLibros];

        // Recorremos cada libro y pedimos los datos
        for (int j = 0; j < bibliotecas[i].cantidadLibros; j++) {
            cout << "\nLibro " << j + 1 << ": " << endl;

            cout << "Introduce su Titulo: ";
            getline(cin, bibliotecas[i].libros[j].titulo);

            cout << "Introduce su autor: ";
            getline(cin, bibliotecas[i].libros[j].autor);

            cout << "Introduce su año de publicacion: ";
            cin >> bibliotecas[i].libros[j].anioPublicacion;
            cin.ignore();
        }
    }

    char opcion;

    // Bucle para añadir nuevas bibliotecas si el usuario lo desea
    do {
        cout << "\n¿Desea introducir una nueva biblioteca? (s/n): ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 's' || opcion == 'S') {

            // Creamos un nuevo array con espacio adicional
            Biblioteca* nuevoArray = new Biblioteca[bibliotecasTotales + 1];

            // Copiamos las bibliotecas ya existentes
            for (int i = 0; i < bibliotecasTotales; i++) {
                nuevoArray[i] = bibliotecas[i];
            }

            // Pedimos los datos de la nueva biblioteca
            cout << "\nIntroduce el nombre de la nueva biblioteca: ";
            getline(cin, nuevoArray[bibliotecasTotales].nombre);

            cout << "Introduce la ciudad: ";
            getline(cin, nuevoArray[bibliotecasTotales].ciudad);

            cout << "¿Cuantos libros deseas introducir?: ";
            cin >> nuevoArray[bibliotecasTotales].cantidadLibros;
            cin.ignore();

            // Creamos el array dinámico de libros para la nueva biblioteca
            nuevoArray[bibliotecasTotales].libros = new Libro[nuevoArray[bibliotecasTotales].cantidadLibros];

            for (int j = 0; j < nuevoArray[bibliotecasTotales].cantidadLibros; j++) {
                cout << "\nLibro " << j + 1 << ": " << endl;

                cout << "Titulo: ";
                getline(cin, nuevoArray[bibliotecasTotales].libros[j].titulo);

                cout << "Autor: ";
                getline(cin, nuevoArray[bibliotecasTotales].libros[j].autor);

                cout << "Anio de publicacion: ";
                cin >> nuevoArray[bibliotecasTotales].libros[j].anioPublicacion;
                cin.ignore();
            }

            // Eliminamos el array antiguo y actualizamos el puntero
            delete[] bibliotecas;
            bibliotecas = nuevoArray;

            // Aumentamos el contador total
            bibliotecasTotales++;
        }

    } while (opcion == 's' || opcion == 'S');

    // Mostramos los datos finales de todas las bibliotecas
    for (int i = 0; i < bibliotecasTotales; i++) {
        cout << "\nBiblioteca " << i + 1 << ": " << endl;
        cout << "Nombre: " << bibliotecas[i].nombre << endl;
        cout << "Ciudad: " << bibliotecas[i].ciudad << endl;
        cout << "La biblioteca " << bibliotecas[i].nombre << " tiene los siguientes libros: " << endl;

        for (int j = 0; j < bibliotecas[i].cantidadLibros; j++) {
            cout << "\nLibro " << j + 1 << ": " << endl;
            cout << "Titulo: " << bibliotecas[i].libros[j].titulo << endl;
            cout << "Autor: " << bibliotecas[i].libros[j].autor << endl;
            cout << "Anio de publicacion: " << bibliotecas[i].libros[j].anioPublicacion << endl;
        }
    }

    // Liberamos toda la memoria dinámica usada
    for (int i = 0; i < bibliotecasTotales; i++) {
        delete[] bibliotecas[i].libros;
    }

    delete[] bibliotecas;

    return 0;
}
