/*
    SISTEMA DE GESTIÓN DE INVENTARIO - Reto final

    1. Registrar N productos (nombre, precio, cantidad)
    2. Mostrar productos ordenados por:
        a) Valor total (precio × cantidad) de mayor a menor
        b) Nombre alfabéticamente (A-Z)
    3. Filtrar por:
        a) Productos con valor total > 100
        b) Productos con menos de 5 unidades
    4. Buscar un producto por nombre (usuario introduce un nombre)
    5. Modificar el stock de un producto (por nombre)
    6. Mostrar el inventario final actualizado

    → Usa memoria dinámica y estructuras
    → Usa funciones separadas para cada acción
    → Reutiliza todo lo que ya sabes
*/


#include <iostream>
using namespace std;


struct Producto {

    string nombre;
    float precio;
    int cantidad;

};

void cargarProductos(Producto* lista, int cantidad){

    cout << "-------Ingrese los productos-------" << endl;
    for (int i = 0; i < cantidad; i++){

        cout << "Producto " << i + 1 << ": ";
        cin >> lista[i].nombre;
        cout << "Precio: "; 
        cin >> lista[i].precio;
        cout << "Cantidad: ";
        cin >> lista[i].cantidad;
    }
}

void mostrarProductos(Producto* lista, int cantidad) {
    cout << "\n------- Lista de productos -------" << endl;

    for (int i = 0; i < cantidad; i++) {
        cout << "\nProducto " << i + 1 << endl;
        cout << "Nombre   : " << lista[i].nombre << endl;
        cout << "Precio   : " << lista[i].precio << " euros" << endl;
        cout << "Cantidad : " << lista[i].cantidad << " unidades" << endl;
    }
}


void ordenarMayorMenor(Producto* lista, int cantidad){

    for(int i = 0; i < cantidad; i++){
        for(int j = i + 1; j < cantidad; j++){
            float valorI = lista[i].precio * lista[i].cantidad;
            float valorJ = lista[j].precio * lista[j].cantidad;

            if (valorJ > valorI){
                Producto temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

void ordenarAlfabeticamenteNombre(Producto* lista, int cantidad){

    for (int i = 0; i < cantidad; i++){
        for (int j = i + 1; j < cantidad; j++){
            
            if (lista[j].nombre < lista[i].nombre){
                Producto temp = lista[i];
                lista[i] = lista[j];
                lista[j] = temp;
            }
        }
    }
}

void mostrarProductosMayoresQue100(Producto* lista, int cantidad){

    cout << "Los productos con un stock mayor que 100 son: ";

    for (int i = 0; i < cantidad; i++){

        float valorTotal = lista[i].precio * lista[i].cantidad;
        int contador = 0;

        if (valorTotal > 100){

            contador++;
            cout << "\nProducto " << contador << endl;
            cout << "Nombre   : " << lista[i].nombre << endl;
            cout << "Precio   : " << lista[i].precio << " euros" << endl;
            cout << "Cantidad : " << lista[i].cantidad << " unidades" << endl;
            
        }
    }
}

void stockMenorQue5(Producto* lista, int cantidad){
    int contador = 0;

    cout << "Los productos con menos de 5 unidades son: ";

    for (int i = 0; i < cantidad; i++){

       

        if (lista[i].cantidad < 5){

            cout << "Producto " << contador << ": " << lista[i].nombre;
        }
    }
}

void buscarProductoPorNombre(Producto* lista, int cantidad, string buscarProducto){

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++){

        if (buscarProducto == lista[i].nombre){

            encontrado = true;

            cout << buscarProducto << " se encuentra en la lista." << endl;
            cout << "Precio   : " << lista[i].precio << " euros" << endl;
            cout << "Cantidad : " << lista[i].cantidad << " unidades" << endl;

        }
        
    }

    if (!encontrado){

        cout << "\n❌ El producto \"" << buscarProducto << "\" no se encuentra en la lista." << endl;
    }
}

void modificarStock(Producto* lista, int cantidad, string nombreParaEditar){

    bool encontrado = false;

    for (int i = 0; i < cantidad; i++){

        if (nombreParaEditar == lista[i].nombre){

            encontrado = true;

            cout << "Precio actual: " << lista[i].precio;
            cout << "Cantidad actual: " << lista[i].cantidad;

            cout << "Introduce el nuevo precio: ";
            cin >> lista[i].precio;

            cout << "Introduce la nueva cantidad: ";
            cin >> lista[i].cantidad;
            break;

        }
    }

    if (!encontrado){

        cout << "El producto " << nombreParaEditar << " no existe." << endl;
    }


}


int main(){

    int cantidad;
    cout << "¿Cuántos productos desea registrar? ";
    cin >> cantidad;

    Producto* lista = new Producto[cantidad];
    cargarProductos(lista, cantidad);



    int opcion;

    do
    {
        cout << "\n====== MENÚ DE GESTIÓN DE INVENTARIO ======" << endl;
        cout << "1. Mostrar todos los productos" << endl;
        cout << "2. Ordenar por valor total (mayor a menor)" << endl;
        cout << "3. Ordenar por nombre (A-Z)" << endl;
        cout << "4. Mostrar productos con valor total > 100€" << endl;
        cout << "5. Mostrar productos con menos de 5 unidades" << endl;
        cout << "6. Buscar producto por nombre" << endl;
        cout << "7. Modificar stock de un producto" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarProductos(lista, cantidad);
                break;

            case 2:
                ordenarMayorMenor(lista, cantidad);
                cout << "\nProductos ordenados por valor total (mayor a menor):" << endl;
                mostrarProductos(lista, cantidad);
                break;

            case 3:
                ordenarAlfabeticamenteNombre(lista, cantidad);
                cout << "\nProductos ordenados por nombre (A-Z):" << endl;
                mostrarProductos(lista, cantidad);
                break;

            case 4:
                mostrarProductosMayoresQue100(lista, cantidad);
                break;

            case 5:
                stockMenorQue5(lista, cantidad);
                break;

            case 6: {
                string nombreBuscar;
                cout << "Introduce el nombre del producto a buscar: ";
                cin >> nombreBuscar;
                buscarProductoPorNombre(lista, cantidad, nombreBuscar);
                break;
            }

            case 7: {
                string nombreEditar;
                cout << "Introduce el nombre del producto a modificar: ";
                cin >> nombreEditar;
                modificarStock(lista, cantidad, nombreEditar);
                break;
            }

            case 0:
                cout << "\nSaliendo del programa. ¡Hasta luego!" << endl;
                break;

            default:
                cout << "❌ Opción no válida. Intente de nuevo." << endl;
                break;
        }

    } while (opcion != 0);
    

    delete [] lista;
    return 0;

}

