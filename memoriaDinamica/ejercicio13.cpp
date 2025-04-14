/*
===============================
📚 EJERCICIO: Gestión de Préstamos de Libros
===============================

Este programa permite gestionar una biblioteca con las siguientes funcionalidades:

1. Registrar libros con su título, autor, año, stock y lista de préstamos.
2. Registrar préstamos realizados por lectores.
3. Mostrar el listado de libros con su historial de préstamos.
4. Validar si un libro tiene stock disponible antes de permitir el préstamo.
5. Gestionar memoria dinámica con estructuras anidadas (array de estructuras dentro de otra estructura).
6. Reforzar el uso de punteros, arrays dinámicos, estructuras y menús interactivos.

📌 Cada libro tendrá una lista dinámica de préstamos, con:
   - Nombre del lector
   - Fecha del préstamo

🎯 Objetivo: aplicar todo lo aprendido y subir el nivel manejando relaciones entre estructuras y punteros de forma más avanzada.

*/


#include <iostream>
using namespace std;

// Estructura para almacenar un préstamo
struct Prestamo {
    string lector;
    string fecha;
};

// Estructura para representar un libro
struct Libro {
    string titulo;
    string autor;
    int anio;
    int stock;
    Prestamo* prestamos;       // Array dinámico de préstamos
    int cantidadPrestamos;     // Número actual de préstamos
};

// Función para cargar los libros
void cargarLibros(Libro* lista, int cantidad) {
    cout << "Por favor, introduce los datos necesarios:" << endl;

    for (int i = 0; i < cantidad; i++) {
        cin.ignore();
        cout << "\nLibro número " << i + 1 << endl;

        cout << "Título: ";
        getline(cin, lista[i].titulo);

        cout << "Autor: ";
        getline(cin, lista[i].autor);

        cout << "Año: ";
        cin >> lista[i].anio;

        cout << "Stock: ";
        cin >> lista[i].stock;

        // Inicializar array de préstamos por cada libro
        lista[i].prestamos = new Prestamo[10];
        lista[i].cantidadPrestamos = 0;
    }
}

// Función para registrar un préstamo
void registrarPrestamos(Libro* lista, int cantidad, string tituloBuscado) {
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (tituloBuscado == lista[i].titulo) {
            encontrado = true;

            if (lista[i].stock > 0) {
                cin.ignore();
                cout << "Introduce el nombre del propietario: ";
                getline(cin, lista[i].prestamos[lista[i].cantidadPrestamos].lector);

                cout << "Introduce la fecha del préstamo (DD/MM/AAAA): ";
                getline(cin, lista[i].prestamos[lista[i].cantidadPrestamos].fecha);

                lista[i].cantidadPrestamos++;
                lista[i].stock--;

                cout << "✅ Préstamo registrado con éxito." << endl;
            } else {
                cout << "❌ No se puede realizar el préstamo. No hay stock disponible." << endl;
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "❌ Este libro no existe en la biblioteca." << endl;
    }
}

// Función para mostrar el historial de préstamos de un libro
void mostrarHistorialPrestamosPorLibro(Libro* lista, int cantidad, string tituloBuscado) {
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (tituloBuscado == lista[i].titulo) {
            encontrado = true;

            if (lista[i].cantidadPrestamos == 0) {
                cout << "ℹ️ El libro \"" << tituloBuscado << "\" no tiene préstamos registrados.\n";
            } else {
                cout << "\n📚 Historial de préstamos de \"" << tituloBuscado << "\":" << endl;
                for (int j = 0; j < lista[i].cantidadPrestamos; j++) {
                    cout << "\nPréstamo " << j + 1 << ":\n";
                    cout << "  Cliente: " << lista[i].prestamos[j].lector << endl;
                    cout << "  Fecha  : " << lista[i].prestamos[j].fecha << endl;
                }
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "❌ El libro \"" << tituloBuscado << "\" no existe en la biblioteca." << endl;
    }
}

// Función para mostrar todos los libros disponibles
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

// Función para buscar un libro por su título
void buscarLibroPorTitulo(Libro* lista, int cantidad, string titulo) {
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (titulo == lista[i].titulo) {
            encontrado = true;
            if (lista[i].stock > 0) {
                cout << "✅ " << titulo << " se encuentra en la lista y tiene " << lista[i].stock << " en stock." << endl;
            } else {
                cout << "⚠️ " << titulo << " está en la lista pero no hay stock disponible." << endl;
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "❌ El libro \"" << titulo << "\" no se encuentra en la lista." << endl;
    }
}

// Mostrar libros anteriores al año 2000
void mostrarLibrosAntesDel2000(Libro* lista, int cantidad) {
    int indice = 0;

    cout << "\n📘 Libros anteriores al año 2000:\n";
    for (int i = 0; i < cantidad; i++) {
        if (lista[i].anio < 2000) {
            indice++;
            cout << indice << ". " << lista[i].titulo << " - " << lista[i].autor << " (" << lista[i].anio << ")\n";
        }
    }

    if (indice == 0) {
        cout << "No hay libros anteriores al año 2000 en el catálogo." << endl;
    }
}

// Ordenar libros por año (de más antiguo a más reciente)
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

// Modificar stock de un libro por título
void modificarStockLibro(Libro* lista, int cantidad, string titulo) {
    bool encontrado = false;

    for (int i = 0; i < cantidad; i++) {
        if (titulo == lista[i].titulo) {
            encontrado = true;
            cout << "Stock actual de \"" << titulo << "\": " << lista[i].stock << endl;
            cout << "Introduce la nueva cantidad en stock: ";
            cin >> lista[i].stock;
            cout << "✅ Stock actualizado con éxito.\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "❌ El libro \"" << titulo << "\" no se encuentra disponible." << endl;
    }
}

// Mostrar libros agotados (stock = 0)
void mostrarLibrosSinStock(Libro* lista, int cantidad) {
    int indice = 0;
    cout << "\n📦 LIBROS AGOTADOS (STOCK = 0):\n";

    for (int i = 0; i < cantidad; i++) {
        if (lista[i].stock == 0) {
            indice++;
            cout << indice << ". " << lista[i].titulo << endl;
        }
    }

    if (indice == 0) {
        cout << "Todos los libros tienen unidades disponibles." << endl;
    }
}

// Función principal
int main() {
    int cantidad;

    cout << "¿Cuántos libros vas a introducir en el stock de la biblioteca? ";
    cin >> cantidad;

    Libro* lista = new Libro[cantidad];

    cargarLibros(lista, cantidad);

    int opcion;
    string tituloBuscado;

    do {
        cout << "\n========== MENÚ BIBLIOTECA ==========" << endl;
        cout << "1. Mostrar todos los libros" << endl;
        cout << "2. Buscar libro por título" << endl;
        cout << "3. Mostrar libros anteriores al año 2000" << endl;
        cout << "4. Ordenar libros por año de publicación" << endl;
        cout << "5. Modificar stock de un libro" << endl;
        cout << "6. Mostrar libros sin stock" << endl;
        cout << "7. Registrar préstamo de un libro" << endl;
        cout << "8. Ver historial de préstamos de un libro" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarLibros(lista, cantidad);
                break;

            case 2:
                cin.ignore();
                cout << "Introduce el título del libro: ";
                getline(cin, tituloBuscado);
                buscarLibroPorTitulo(lista, cantidad, tituloBuscado);
                break;

            case 3:
                mostrarLibrosAntesDel2000(lista, cantidad);
                break;

            case 4:
                ordenarLibrosAnioPublicacion(lista, cantidad);
                mostrarLibros(lista, cantidad);
                break;

            case 5:
                cin.ignore();
                cout << "Introduce el título del libro: ";
                getline(cin, tituloBuscado);
                modificarStockLibro(lista, cantidad, tituloBuscado);
                break;

            case 6:
                mostrarLibrosSinStock(lista, cantidad);
                break;

            case 7:
                cin.ignore();
                cout << "Introduce el título del libro a prestar: ";
                getline(cin, tituloBuscado);
                registrarPrestamos(lista, cantidad, tituloBuscado);
                break;

            case 8:
                cin.ignore();
                cout << "Introduce el título del libro: ";
                getline(cin, tituloBuscado);
                mostrarHistorialPrestamosPorLibro(lista, cantidad, tituloBuscado);
                break;

            case 0:
                cout << "\nSaliendo del programa. ¡Hasta luego!" << endl;
                break;

            default:
                cout << "❌ Opción no válida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 0);

    // Liberar memoria de los arrays de préstamos
    for (int i = 0; i < cantidad; i++) {
        delete[] lista[i].prestamos;
    }
    delete[] lista;

    return 0;
}
