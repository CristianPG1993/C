/*
=========================================
🎬 ENUNCIADO - GESTIÓN DE PELÍCULAS Y ALQUILERES
=========================================

Crea un programa en C++ que permita gestionar el catálogo de un videoclub.

Cada película debe tener los siguientes datos:
- Título (string)
- Género (string)
- Año de estreno (int)
- Precio por alquiler (float)
- Unidades disponibles en stock (int)

Además, cada película debe tener un historial de alquileres almacenado mediante un array dinámico.
Cada alquiler registrado deberá incluir:
- Nombre del cliente (string)
- Fecha del alquiler (string)

El programa debe permitir al usuario realizar las siguientes acciones mediante un menú:

1. Cargar los datos de las películas
2. Mostrar todo el catálogo
3. Buscar una película por título
4. Ordenar las películas por año de estreno (de más reciente a más antigua)
5. Mostrar las películas con precio superior a 5 €
6. Mostrar las películas con menos de 2 unidades en stock
7. Registrar un nuevo alquiler de una película
8. Mostrar el historial de alquileres de una película específica
9. Modificar el precio o el stock de una película
0. Salir del programa

Extras opcionales:
- Mostrar los ingresos totales generados por los alquileres
- Eliminar una película del catálogo
*/


#include <iostream>
using namespace std;


// Estructura que representa un alquiler de película
struct Alquiler {
    string nombreCliente;    // Nombre del cliente que alquiló la película
    string fechaAlquiler;    // Fecha del alquiler (por ejemplo: "2025-04-14")
};

// Estructura que representa una película del catálogo
struct Pelicula {
    string titulo;              // Título de la película
    string genero;              // Género (comedia, acción, etc.)
    int anioEstreno;            // Año de estreno
    float precioAlquiler;       // Precio por alquiler
    int stock;                  // Unidades disponibles

    Alquiler* alquileres;       // Array dinámico de alquileres
    int contadorAlquiler;       // Número de veces que se alquiló
};


void cargarPeliculas(Pelicula* lista, int cantidad){

    for (int i = 0; i < cantidad; i++){
        
        cout << "\nPelicula " << i + 1 << ": " << endl;
        cout << "Titulo: ";
        cin.ignore();
        getline(cin, lista[i].titulo);

        cout << "Genero: ";
        getline(cin, lista[i].genero);

        cout << "Anio de estreno: ";
        cin >> lista[i].anioEstreno;

        cout << "Precio del alquiler: ";
        cin >> lista[i].precioAlquiler;

        cout << "Stock: ";
        cin >> lista[i].stock;


        lista[i].alquileres = nullptr;
        lista[i].contadorAlquiler = 0;

    }
}

void mostrarPeliculasRegistradas(Pelicula* lista, int cantidad){

    cout << "\nPeliculas registradas: " << endl;
    for (int i = 0; i < cantidad; i++ ){

        cout << "\nTitulo: " << lista[i].titulo << endl;
        cout << "Genero: " << lista[i].genero << endl;
        cout << "Anio de estreno: " << lista[i].anioEstreno << endl;
        cout << "Precio del alquiler: " << lista[i].precioAlquiler << endl;
        cout << "Stock: " << lista[i].stock << endl;
        cout << "Alquileres realizados: " << lista[i].contadorAlquiler << endl;
        cout << "--------------------------------------------" << endl;
    }
}

void buscarPeliculaPorTitulo(Pelicula* lista, int cantidad, string tituloBuscado){

    bool encontrado = false;

    cout << "\nIntroduce el titulo que desea encontrar: " << endl;
    cin.ignore();
    getline(cin, tituloBuscado);

    for (int i = 0; i < cantidad; i++){

        if(tituloBuscado == lista[i].titulo){

            encontrado = true;
            cout << "\nPelicula encontrada: " << endl;
            cout << "Titulo: " << lista[i].titulo << endl;
            cout << "Genero: " << lista[i].genero << endl;
            cout << "Anio de estreno: " << lista[i].anioEstreno << endl;
            cout << "Precio del alquiler: " << lista[i].precioAlquiler << " euros." << endl;
            cout << "Stock: " << lista[i].stock << endl;
            cout << "Veces alquilada: " << lista[i].contadorAlquiler << endl;

        }

    }
    if (!encontrado){

        cout << tituloBuscado << " no se encuentra en la lista." << endl;
    }

}

void ordenarPeliculasPorAñoEstreno(Pelicula* lista, int cantidad){

    cout << "\nPeliculas ordenadas por anio de estreno: " << endl;

    for (int i = 0; i < cantidad; i++){
        for (int j = i + 1; j < cantidad; j++){

            if(lista[j].anioEstreno > lista[i].anioEstreno){
                Pelicula temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;

            }
        }
    }

    cout << "\nPleiculas ordenadas por anio de estreno (de más reciente a más antigua)." << endl;

}

void alquilerMayor5(Pelicula* lista, int cantidad){

    bool encontrado = false;

    cout << "\nPeliculas con el precio del alquiler mayor a 5 euros:" << endl;
    for(int i = 0; i < cantidad; i++){

        if (lista[i].precioAlquiler > 5){
            encontrado = true;

            cout << "\nPelicula " << i + 1 << ": " << endl;
            cout << "Titulo: " << lista[i].titulo << endl;
            cout << "Genero: " << lista[i].genero << endl;
            cout << "Anio de estreno: " << lista[i].anioEstreno << endl;
            cout << "Precio: " << lista[i].precioAlquiler << " euros." << endl;
            cout << "Stock: " << lista[i].stock << endl;
            cout << "Veces alquiladas: " << lista[i].contadorAlquiler << endl;
            cout << "---------------------------------------------------" << endl;
            

        }
        

    }
    if(!encontrado){

        cout << "\nNo hay peliculas con un precio de alquiler mayor a 5 euros. " << endl;

    }
}

void mostrarStockMenor2(Pelicula* lista, int cantidad){
    bool encontrado = false;

    cout << "\nPeliculas con menos de 2 unidades de stock: " << endl;

    for (int i = 0; i < cantidad; i++){

        if(lista[i].stock < 2){
            encontrado = true;

            cout << "\nPelicula " << i + 1 << ": " << endl;
            cout << "Titulo: " << lista[i].titulo << endl;
            cout << "Genero: " << lista[i].genero << endl;
            cout << "Anio de estreno: " << lista[i].anioEstreno << endl;
            cout << "Precio: " << lista[i].precioAlquiler << " euros." << endl;
            cout << "Stock: " << lista[i].stock << endl;
            cout << "Veces alquiladas: " << lista[i].contadorAlquiler << endl;
            cout << "---------------------------------------------------" << endl;
        }
    }
    if(!encontrado){

        cout << "\nTodas las peliculas tienen al menos 2 unidades en stock. " << endl;
    }
}

void registrarNuevoAlquiler(Pelicula* lista, int cantidad){

    string nombrePelicula;
    bool encontrado = false;

    cout << "Introduce el titulo de la pelicula para registrar el nuevo alquiler: " << endl;
    cin.ignore();
    getline(cin, nombrePelicula);

    for (int i = 0; i < cantidad; i++){

        if(nombrePelicula == lista[i].titulo){

            encontrado = true;

            if(lista[i].stock > 0){

                Alquiler nuevoAlquiler;

                cout << "\nIntroduce el nombre del cliente: ";
                cin.ignore();
                getline(cin, nuevoAlquiler.nombreCliente);

                cout << "\nIntroduce la fecha del alquiler(DD-MM-YYYY):";
                cin >> nuevoAlquiler.fechaAlquiler;

                Alquiler* nuevosAlquileres = new Alquiler[lista[i].alquileres + 1];
                for (j = 0; j < lista[i].alquileres; j++){

                    nuevosAlquileres[j] = lista[i].contadorAlquiler[j];
                }

                nuevosAlquileres[lista[i].contadorAlquiler] = nuevoAlquiler;

                delete [] lista[i].alquileres;
                lista[i].alquileres = nuevosAlquileres;
                lista[i].contadorAlquiler++;
                lista[i].stock--;
                
                cout << "\nAlquiler registrada con éxito.\n";

            }else {
                cout << "\nNo hay stock disponible.\n";
            }
            break;
        }
    }
    if (!encontrado) {
        cout << "\nPelicula no encontrada.\n";
    }
}

void mostrarAlquileresPelicula(Pelicula* lista, int cantidad, string tituloBuscado){
    bool encontrado = false;

    cout << "Introduce el titulo de la pelicula que desea ver el historial: " << endl;
    cin.ignore();
    getline(cin, tituloBuscado);

    for (int i = 0; i < cantidad; i++){

        if (tituloBuscado == lista[i].titulo){
            encontrado = true;

            if(lista[i].contadorAlquiler == 0){

                cout << "\nLa pelicula " << tituloBuscado << " no ha sido alquilada todavía." << endl;

            } else{

                for (int j = 0; j < lista[i].contadorAlquiler; j++){

                    cout << "\nAlquiler " << j + 1 << ": " << endl;
                    cout << "Nombre del cliente: " << lista[i].alquileres[j].nombreCliente << endl;
                    cout << "Fecha del alquiler: " << lista[i].alquileres[j].fechaAlquiler << endl;
                }
            }break;


        }
    }

    if(!encontrado){

        cout << "\nPelicula no encontrada.\n";
    }
}

void modificarPrecio(Pelicula* lista, int cantidad){

    string tituloBuscado
    bool encontrado = false;
    
    cout << "\nIntroduce el nombre de la pelicula que desea modificar el precio: " << endl;
    cin.ignore();
    getline(cin, tituloBuscado);

    for (int i = 0; i < cantidad; i++){

        if (tituloBuscado == lista[i].titulo){
            encontrado = true;

            cout << "\nPrecio actual: " << lista[i].precioAlquiler << " euros." << endl;
            cout <<"Introduce el precio nuevo: " << endl;
            cin >> lista[i].precioAlquiler;


        }
    } if(!encontrado){

        cout << "\nLa pelicula " << tituloBuscado << " no se encuentra en el catálogo." << endl;

    }
}

int main() {
    int cantidad = 0;                  // Número de películas
    int opcion;                        // Opción elegida en el menú
    Pelicula* lista = nullptr;         // Array dinámico para las películas

    do {
        // Mostrar el menú
        cout << "\n========== 🎥 MENÚ VIDEOCLUB ==========" << endl;
        cout << "1. Cargar datos de las películas" << endl;
        cout << "2. Mostrar todo el catálogo" << endl;
        cout << "3. Buscar una película por título" << endl;
        cout << "4. Ordenar películas por año de estreno" << endl;
        cout << "5. Mostrar películas con precio superior a 5 €" << endl;
        cout << "6. Mostrar películas con menos de 2 unidades en stock" << endl;
        cout << "7. Registrar un nuevo alquiler" << endl;
        cout << "8. Mostrar el historial de alquileres de una película" << endl;
        cout << "9. Modificar el precio de una película" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n¿Cuántas películas deseas introducir? ";
                cin >> cantidad;

                // Liberar memoria previa, si existe
                if (lista != nullptr) {
                    for (int i = 0; i < cantidad; i++) {
                        delete[] lista[i].alquileres;
                    }
                    delete[] lista;
                }

                lista = new Pelicula[cantidad];
                cargarPeliculas(lista, cantidad);
                break;

            case 2:
                if (lista != nullptr)
                    mostrarPeliculasRegistradas(lista, cantidad);
                break;

            case 3:
                if (lista != nullptr) {
                    string tituloBuscado;
                    buscarPeliculaPorTitulo(lista, cantidad, tituloBuscado);
                }
                break;

            case 4:
                if (lista != nullptr) {
                    ordenarPeliculasPorAñoEstreno(lista, cantidad);
                    mostrarPeliculasRegistradas(lista, cantidad);
                }
                break;

            case 5:
                if (lista != nullptr)
                    alquilerMayor5(lista, cantidad);
                break;

            case 6:
                if (lista != nullptr)
                    mostrarStockMenor2(lista, cantidad);
                break;

            case 7:
                if (lista != nullptr)
                    registrarNuevoAlquiler(lista, cantidad);
                break;

            case 8:
                if (lista != nullptr) {
                    string tituloBuscado;
                    mostrarAlquileresPelicula(lista, cantidad, tituloBuscado);
                }
                break;

            case 9:
                if (lista != nullptr)
                    modificarPrecio(lista, cantidad);
                break;

            case 0:
                cout << "\n📽️ Saliendo del programa. ¡Hasta pronto!" << endl;
                break;

            default:
                cout << "❌ Opción no válida, intente de nuevo." << endl;
                break;
        }

    } while (opcion != 0);

    // Liberar memoria al salir
    if (lista != nullptr) {
        for (int i = 0; i < cantidad; i++) {
            delete[] lista[i].alquileres;
        }
        delete[] lista;
    }

    return 0;
}
