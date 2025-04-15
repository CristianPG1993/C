/*
=========================================
🚗 ENUNCIADO - GESTIÓN DE VEHÍCULOS CON HISTORIAL DE VENTAS
=========================================

Crea un programa en C++ que permita gestionar el inventario de un concesionario de vehículos.

Cada vehículo debe tener los siguientes datos:
- Marca (string)
- Modelo (string)
- Año de fabricación (int)
- Precio (float)
- Unidades disponibles en stock (int)

Además, cada vehículo debe tener un historial de ventas almacenado mediante un array dinámico.
Cada venta registrada deberá incluir:
- Nombre del comprador (string)
- Fecha de la venta (string)

El programa debe permitir al usuario realizar las siguientes acciones mediante un menú:

1. Cargar los datos de los vehículos (reserva memoria también para las ventas).
2. Mostrar todos los vehículos registrados.
3. Buscar un vehículo por marca y modelo.
4. Ordenar los vehículos por año de fabricación (de más reciente a más antiguo).
5. Ordenar los vehículos por precio (de mayor a menor).
6. Mostrar los vehículos con precio superior a 20.000€.
7. Mostrar los vehículos con menos de 3 unidades en stock.
8. Registrar una nueva venta de un vehículo.
9. Mostrar el historial de ventas de un vehículo específico.
10. Modificar el precio o stock de un vehículo.
0. Salir del programa.

Extras opcionales:
- Mostrar los ingresos totales generados por ventas.
- Eliminar un vehículo del inventario.
*/

#include <iostream>
#include <string>
using namespace std;

// Estructura que representa una venta individual
struct Venta {
    string nombreComprador; // Nombre del comprador
    string fechaVenta;      // Fecha de la venta
};

// Estructura que representa un vehículo con su historial de ventas
struct Vehiculo {
    string marca;              // Marca del vehículo
    string modelo;             // Modelo del vehículo
    int anioFabricacion;       // Año de fabricación
    float precio;              // Precio del vehículo
    int stock;                 // Unidades disponibles
    Venta* ventas;             // Array dinámico de ventas
    int cantidadVentas;        // Número de ventas realizadas
};

// Función para cargar los datos de los vehículos
void cargarVehiculos(Vehiculo* lista, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "\nDatos del vehículo " << i + 1 << ":" << endl;

        cout << "Marca: ";
        cin >> lista[i].marca;
        cout << "Modelo: ";
        cin >> lista[i].modelo;
        cout << "Año de fabricación: ";
        cin >> lista[i].anioFabricacion;
        cout << "Precio: ";
        cin >> lista[i].precio;
        cout << "Stock: ";
        cin >> lista[i].stock;

        lista[i].ventas = nullptr;       // Inicialmente no hay ventas
        lista[i].cantidadVentas = 0;
    }
}

// Función para mostrar todos los vehículos registrados
void mostrarVehiculosRegistrados(Vehiculo* lista, int cantidad) {
    cout << "\n=== Vehículos registrados ===" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << "\nVehículo " << i + 1 << ":" << endl;
        cout << "Marca: " << lista[i].marca << endl;
        cout << "Modelo: " << lista[i].modelo << endl;
        cout << "Año: " << lista[i].anioFabricacion << endl;
        cout << "Precio: " << lista[i].precio << " €" << endl;
        cout << "Stock: " << lista[i].stock << endl;
        cout << "Ventas registradas: " << lista[i].cantidadVentas << endl;
    }
}

// Función para buscar un vehículo por marca y modelo
void buscarPorMarcaModelo(Vehiculo* lista, int cantidad) {
    string marca, modelo;
    bool encontrado = false;

    cout << "\nIntroduce la marca: ";
    cin >> marca;
    cout << "Introduce el modelo: ";
    cin >> modelo;

    for (int i = 0; i < cantidad; i++) {
        if (lista[i].marca == marca && lista[i].modelo == modelo) {
            encontrado = true;

            cout << "\nVehículo encontrado:" << endl;
            cout << "Marca: " << lista[i].marca << endl;
            cout << "Modelo: " << lista[i].modelo << endl;
            cout << "Año: " << lista[i].anioFabricacion << endl;
            cout << "Precio: " << lista[i].precio << " €" << endl;
            cout << "Stock: " << lista[i].stock << endl;
            break;
        }
    }

    if (!encontrado) {
        cout << "\nEl vehículo no se encuentra en el inventario." << endl;
    }
}

// Ordenar por año de fabricación (de más reciente a más antiguo)
void ordenarPorAnio(Vehiculo* lista, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        for (int j = i + 1; j < cantidad; j++) {
            if (lista[j].anioFabricacion > lista[i].anioFabricacion) {
                Vehiculo temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

// Ordenar por precio (de mayor a menor)
void ordenarPorPrecio(Vehiculo* lista, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        for (int j = i + 1; j < cantidad; j++) {
            if (lista[j].precio > lista[i].precio) {
                Vehiculo temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

// Mostrar vehículos con precio superior a 20.000 €
void mostrarVehiculosSuperiores20000(Vehiculo* lista, int cantidad) {
    bool encontrado = false;
    cout << "\nVehículos con precio superior a 20.000 €:\n";

    for (int i = 0; i < cantidad; i++) {
        if (lista[i].precio > 20000) {
            encontrado = true;
            cout << "Marca: " << lista[i].marca
                 << ", Modelo: " << lista[i].modelo
                 << ", Precio: " << lista[i].precio << " €\n";
        }
    }

    if (!encontrado) {
        cout << "No se encontraron vehículos con precio superior a 20.000 €.\n";
    }
}

// Mostrar vehículos con menos de 3 unidades
void stockMenor3(Vehiculo* lista, int cantidad) {
    bool encontrado = false;
    cout << "\nVehículos con menos de 3 unidades en stock:\n";

    for (int i = 0; i < cantidad; i++) {
        if (lista[i].stock < 3) {
            encontrado = true;
            cout << "Marca: " << lista[i].marca
                 << ", Modelo: " << lista[i].modelo
                 << ", Stock: " << lista[i].stock << "\n";
        }
    }

    if (!encontrado) {
        cout << "Todos los vehículos tienen 3 unidades o más.\n";
    }
}

// Registrar una nueva venta
void registroVentaVehiculo(Vehiculo* lista, int cantidad) {
    string marca, modelo;
    bool encontrado = false;

    cout << "\nMarca: ";
    cin >> marca;
    cout << "Modelo: ";
    cin >> modelo;

    for (int i = 0; i < cantidad; i++) {
        if (lista[i].marca == marca && lista[i].modelo == modelo) {
            encontrado = true;

            if (lista[i].stock > 0) {
                Venta nuevaVenta;
                cin.ignore(); // limpiar buffer
                cout << "Nombre del comprador: ";
                getline(cin, nuevaVenta.nombreComprador);
                cout << "Fecha de la venta: ";
                getline(cin, nuevaVenta.fechaVenta);

                // Reservamos nuevo array con 1 espacio adicional
                Venta* nuevasVentas = new Venta[lista[i].cantidadVentas + 1];
                for (int j = 0; j < lista[i].cantidadVentas; j++) {
                    nuevasVentas[j] = lista[i].ventas[j];
                }
                nuevasVentas[lista[i].cantidadVentas] = nuevaVenta;

                delete[] lista[i].ventas; // liberamos memoria anterior
                lista[i].ventas = nuevasVentas;
                lista[i].cantidadVentas++;
                lista[i].stock--;

                cout << "✅ Venta registrada con éxito.\n";
            } else {
                cout << "❌ No hay stock disponible.\n";
            }
            break;
        }
    }

    if (!encontrado) {
        cout << "❌ Vehículo no encontrado.\n";
    }
}

// Mostrar historial de ventas
void mostrarHistorialVentas(Vehiculo* lista, int cantidad) {
    string marca, modelo;
    bool encontrado = false;

    cout << "\nMarca: ";
    cin >> marca;
    cout << "Modelo: ";
    cin >> modelo;

    for (int i = 0; i < cantidad; i++) {
        if (lista[i].marca == marca && lista[i].modelo == modelo) {
            encontrado = true;

            if (lista[i].cantidadVentas > 0) {
                cout << "\nHistorial de ventas:\n";
                for (int j = 0; j < lista[i].cantidadVentas; j++) {
                    cout << "Venta " << j + 1 << ":\n";
                    cout << "  Comprador: " << lista[i].ventas[j].nombreComprador << "\n";
                    cout << "  Fecha: " << lista[i].ventas[j].fechaVenta << "\n";
                }
            } else {
                cout << "Este vehículo no tiene ventas registradas.\n";
            }
            return;
        }
    }

    if (!encontrado) {
        cout << "Vehículo no encontrado.\n";
    }
}

// Modificar el stock de un vehículo
void modificarStock(Vehiculo* lista, int cantidad) {
    string marca, modelo;
    bool encontrado = false;

    cout << "\nMarca: ";
    cin >> marca;
    cout << "Modelo: ";
    cin >> modelo;

    for (int i = 0; i < cantidad; i++) {
        if (lista[i].marca == marca && lista[i].modelo == modelo) {
            encontrado = true;
            cout << "Stock actual: " << lista[i].stock << "\n";
            cout << "Nuevo stock: ";
            cin >> lista[i].stock;
            cout << "✅ Stock actualizado.\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "❌ Vehículo no encontrado.\n";
    }
}

// Modificar el precio de un vehículo
void modificarPrecio(Vehiculo* lista, int cantidad) {
    string marca, modelo;
    bool encontrado = false;

    cout << "\nMarca: ";
    cin >> marca;
    cout << "Modelo: ";
    cin >> modelo;

    for (int i = 0; i < cantidad; i++) {
        if (lista[i].marca == marca && lista[i].modelo == modelo) {
            encontrado = true;
            cout << "Precio actual: " << lista[i].precio << " €\n";
            cout << "Nuevo precio: ";
            cin >> lista[i].precio;
            cout << "✅ Precio actualizado.\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "❌ Vehículo no encontrado.\n";
    }
}



int main() {
    int cantidad = 0;              // Cantidad de vehículos a gestionar
    int opcion;                    // Opción del menú
    Vehiculo* lista = nullptr;     // Puntero al array dinámico de vehículos

    do {
        // Menú de opciones
        cout << "\n========== MENÚ CONCESIONARIO ==========" << endl;
        cout << "1. Cargar datos de los vehículos" << endl;
        cout << "2. Mostrar todos los vehículos registrados" << endl;
        cout << "3. Buscar un vehículo por marca y modelo" << endl;
        cout << "4. Ordenar vehículos por año de fabricación (recientes primero)" << endl;
        cout << "5. Ordenar vehículos por precio (de mayor a menor)" << endl;
        cout << "6. Mostrar vehículos con precio superior a 20.000 €" << endl;
        cout << "7. Mostrar vehículos con menos de 3 unidades en stock" << endl;
        cout << "8. Registrar una nueva venta de un vehículo" << endl;
        cout << "9. Mostrar el historial de ventas de un vehículo específico" << endl;
        cout << "10. Modificar el stock de un vehículo" << endl;
        cout << "11. Modificar el precio de un vehículo" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "¿Cuántos vehículos deseas introducir? ";
                cin >> cantidad;

                // Liberamos memoria anterior si ya existía una lista
                if (lista != nullptr) {
                    for (int i = 0; i < cantidad; i++) {
                        delete[] lista[i].ventas;
                    }
                    delete[] lista;
                }

                // Creamos un nuevo array de vehículos
                lista = new Vehiculo[cantidad];
                cargarVehiculos(lista, cantidad);
                break;

            case 2:
                if (lista != nullptr)
                    mostrarVehiculosRegistrados(lista, cantidad);
                break;

            case 3:
                if (lista != nullptr)
                    buscarPorMarcaModelo(lista, cantidad);
                break;

            case 4:
                if (lista != nullptr) {
                    ordenarPorAnio(lista, cantidad);
                    mostrarVehiculosRegistrados(lista, cantidad);
                }
                break;

            case 5:
                if (lista != nullptr) {
                    ordenarPorPrecio(lista, cantidad);
                    mostrarVehiculosRegistrados(lista, cantidad);
                }
                break;

            case 6:
                if (lista != nullptr)
                    mostrarVehiculosSuperiores20000(lista, cantidad);
                break;

            case 7:
                if (lista != nullptr)
                    stockMenor3(lista, cantidad);
                break;

            case 8:
                if (lista != nullptr)
                    registroVentaVehiculo(lista, cantidad);
                break;

            case 9:
                if (lista != nullptr)
                    mostrarHistorialVentas(lista, cantidad);
                break;

            case 10:
                if (lista != nullptr)
                    modificarStock(lista, cantidad);
                break;

            case 11:
                if (lista != nullptr)
                    modificarPrecio(lista, cantidad);
                break;

            case 0:
                cout << "\nSaliendo del programa. ¡Hasta luego!" << endl;
                break;

            default:
                cout << "❌ Opción no válida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 0);

    // Liberar toda la memoria dinámica al salir
    if (lista != nullptr) {
        for (int i = 0; i < cantidad; i++) {
            delete[] lista[i].ventas;
        }
        delete[] lista;
    }

    return 0;
}

