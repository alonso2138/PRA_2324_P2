#include "DyV.h"
#include <iostream>
#include <vector>

// El "using namespace std;" ya está en DyV.h

int main() {
    cout << "===== Pruebas de Busqueda Binaria (ascendente) =====" << endl;
    vector<int> v_asc = {10, 20, 30, 40, 50, 60};
    cout << "Vector: ";
    imprimirVector(v_asc);
    cout << "Buscando el 30... Posicion: " << busquedaBinaria(30, v_asc, 0, v_asc.size() - 1) << endl; // Debería encontrarlo
    cout << "Buscando el 35... Posicion: " << busquedaBinaria(35, v_asc, 0, v_asc.size() - 1) << endl; // Debería dar -1
    cout << endl;

    cout << "===== Pruebas de Busqueda Binaria (descendente) =====" << endl;
    vector<int> v_desc = {60, 50, 40, 30, 20, 10};
    cout << "Vector: ";
    imprimirVector(v_desc);
    cout << "Buscando el 20... Posicion: " << busquedaBinariaInversa(20, v_desc, 0, v_desc.size() - 1) << endl; // Debería encontrarlo
    cout << "Buscando el 35... Posicion: " << busquedaBinariaInversa(35, v_desc, 0, v_desc.size() - 1) << endl; // Debería dar -1
    cout << endl;

    cout << "===== Pruebas de QuickSort =====" << endl;
    vector<int> v_ord = {40, 10, 50, 20, 60, 30};
    cout << "Vector original: ";
    imprimirVector(v_ord);

    // CORRECCIÓN: El último índice es size() - 1, no size().
    quickSort(v_ord, 0, v_ord.size() - 1);

    cout << "Vector ordenado: ";
    imprimirVector(v_ord);
    cout << endl;

    return 0;
}