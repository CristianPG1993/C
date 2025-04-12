/*
    ======================================================
    EJERCICIO: GESTIÓN DE LIBROS EN UNA BIBLIOTECA
    ======================================================

    Crea un sistema que permita gestionar libros mediante
    estructuras y arrays dinámicos. El programa debe permitir
    almacenar información sobre cada libro, incluyendo:

        - Título del libro
        - Autor
        - Año de publicación
        - Cantidad disponible en stock

    FUNCIONALIDADES QUE DEBE INCLUIR EL MENÚ:

    1. Mostrar todos los libros
    2. Buscar libro por título
    3. Mostrar libros publicados antes del año 2000
    4. Ordenar libros por año de publicación (más antiguo a más reciente)
    5. Modificar el stock de un libro
    6. Mostrar libros sin stock
    0. Salir

    El programa debe utilizar memoria dinámica (`new` y `delete`)
    y todas las funciones deben gestionarse mediante un menú
    interactivo con `do...while`.

*/


#include <iostream>
using namespace std;

// Definición de la estructura Libro
struct Libro {
    string titulo;
    string autor;
    int anio;
    int stock;
};

// Función para cargar los datos de los libros
void cargarLibros(Libro* lista, int cantidad) {
    cout << "Por favor, introduce los datos necesarios:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cin.ignore();  // Limpiar buffer antes de getline
        cout << "Titulo del libro " << i + 1 << ": ";
        getline(cin, lista[i].titulo);

        cout << "Autor: ";
        getline(cin, lista[i].autor);

        cout << "Anio: ";
        cin >> lista[i].anio;

        cout << "Stock: ";
        cin >> lista[i].stock;
    }
};

// Función para mostrar todos los libros cargados
void mostrarLibros(Libro* lista, int cantidad) {
    cout << "\n=== LISTADO DE LIBROS DISPONIBLES ===\n";
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". Título: " << lista[i].titulo << endl;
        cout << "   Autor : " << lista[i].autor << endl;
        cout << "   Año   : " << lista[i].anio << endl;
        cout << "   Stock : " << lista[i].stock << endl;
        cout << "-------------------------------" << endl;
    }
}

// Buscar un libro por título (y mostrar si tiene stock)
void buscarLibroPorTitulo(Libro* lista, int cantidad, string titulo) {
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (titulo == lista[i].titulo) {
            encontrado = true;

            if (lista[i].stock > 0) {
                cout << titulo << " se encuentra en la lista y tiene " << lista[i].stock << " en stock." << endl;
            } else {
                cout << titulo << " se encuentra en la lista pero no hay ningún libro en stock." << endl;
            }
            break; // Salir del bucle una vez encontrado
        }
    }

    if (!encontrado) {
        cout << "El libro " << titulo << " no se encuentra en la lista." << endl;
    }
}

// Mostrar libros publicados antes del año 2000
void mostrarLibrosAntesDel2000(Libro* lista, int cantidad) {
    int indice = 0;

    for (int i = 0; i < cantidad; i++) {
        if (lista[i].anio < 2000) {
            indice++;
            cout << indice << ": " << endl;
            cout << lista[i].titulo << endl;
            cout << lista[i].autor << endl;
            cout << lista[i].anio << endl;
        }
    }

    if (indice == 0) {
        cout << "\nNo hay libros anteriores al año 2000 en el catálogo." << endl;
    }
}

// Ordenar libros de más antiguo a más reciente por año de publicación
void ordenarLibrosAnioPublicacion(Libro* lista, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        for (int j = i + 1; j < cantidad; j++) {
            if (lista[j].anio < lista[i].anio) {
                Libro temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

// Modificar el stock de un libro buscado por título
void modificarStockLibro(Libro* lista, int cantidad, string titulo) {
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (titulo == lista[i].titulo) {
            encontrado = true;
            cout << "El libro " << titulo << " tiene " << lista[i].stock << " en stock." << endl;
            cout << "Introduce la nueva cantidad en stock: " << endl;
            cin >> lista[i].stock;
            cout << "El libro " << titulo << " tiene ahora " << lista[i].stock << " en stock." << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << titulo << " no se encuentra disponible en la biblioteca." << endl;
    }
}

// Mostrar libros que tienen stock en 0 (agotados)
void mostrarLibrosSinStock(Libro* lista, int cantidad) {
    int indice = 0;

    cout << "\n=== LIBROS AGOTADOS (STOCK = 0) ===\n";

    for (int i = 0; i < cantidad; i++) {
        if (lista[i].stock == 0) {
            indice++;
            cout << indice << ": " << endl;
            cout << "Titulo: " << lista[i].titulo << endl;
            cout << "Stock: " << lista[i].stock << endl;
        }
    }

    if (indice == 0) {
        cout << "\n📦 Todos los libros tienen unidades disponibles." << endl;
    }
}

// Función principal
int main() {
    int cantidad;

    // Solicitar al usuario la cantidad de libros a registrar
    cout << "¿Cuántos libros vas a introducir en el stock de la biblioteca? ";
    cin >> cantidad;

    // Crear array dinámico de libros
    Libro* lista = new Libro[cantidad];

    // Cargar libros al inicio
    cargarLibros(lista, cantidad);

    int opcion; // variable para controlar el menú

    // Menú interactivo de opciones
    do {
        cout << "\n### MENU BIBLIOTECA ###" << endl;
        cout << "1. Mostrar todos los libros" << endl;
        cout << "2. Buscar libro por título" << endl;
        cout << "3. Mostrar libros anteriores al año 2000" << endl;
        cout << "4. Libros ordenados por fecha de publicación" << endl;
        cout << "5. Modificación de stock" << endl;
        cout << "6. Mostrar libros no disponibles para préstamo" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción (0 - 6): ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarLibros(lista, cantidad);
                break;

            case 2: {
                string titulo;
                cin.ignore(); // limpiar buffer antes de getline
                cout << "Introduce el título del libro que desea: ";
                getline(cin, titulo);
                buscarLibroPorTitulo(lista, cantidad, titulo);
                break;
            }

            case 3:
                mostrarLibrosAntesDel2000(lista, cantidad);
                break;

            case 4:
                ordenarLibrosAnioPublicacion(lista, cantidad);
                mostrarLibros(lista, cantidad);
                break;

            case 5: {
                string titulo;
                cin.ignore();
                cout << "Introduce el título del libro que desea modificar: ";
                getline(cin, titulo);
                modificarStockLibro(lista, cantidad, titulo);
                break;
            }

            case 6:
                mostrarLibrosSinStock(lista, cantidad);
                break;

            case 0:
                cout << "\nSaliendo del programa. ¡Hasta luego!" << endl;
                break;

            default:
                cout << "Opción no válida. Inténtelo de nuevo." << endl;
                break;
        }

    } while (opcion != 0);

    // Liberar memoria dinámica
    delete[] lista;

    return 0;
}

