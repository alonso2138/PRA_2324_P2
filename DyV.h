#ifndef DYV_H
#define DYV_H

#include <vector>   // Para usar std::vector
#include <iostream> // Para usar std::cout (en el fichero de prueba)

// Usar el espacio de nombres estandar para simplicidad (cout, vector, etc.)
using namespace std;

/**
 * @brief Busca un elemento en un vector ordenado de forma ascendente.
 * @param x Elemento a buscar.
 * @param v Vector (ordenado) donde buscar.
 * @param ini Índice inicial de búsqueda.
 * @param fin Índice final de búsqueda.
 * @return El índice del elemento si se encuentra, o -1 si no.
 */
template <typename T>
int busquedaBinaria(T x, const vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        return -1; // Caso base: elemento no encontrado.
    }

    int medio = ini + (fin - ini) / 2; // Forma segura de calcular el medio para evitar desbordamientos

    if (v[medio] == x) {
        return medio; // Elemento encontrado
    }

    if (v[medio] > x) {
        return busquedaBinaria(x, v, ini, medio - 1); // Buscar en la mitad izquierda
    } else {
        return busquedaBinaria(x, v, medio + 1, fin); // Buscar en la mitad derecha
    }
}

/**
 * @brief Busca un elemento en un vector ordenado de forma descendente.
 * @param x Elemento a buscar.
 * @param v Vector (ordenado inversamente) donde buscar.
 * @param ini Índice inicial de búsqueda.
 * @param fin Índice final de búsqueda.
 * @return El índice del elemento si se encuentra, o -1 si no.
 */
template <typename T>
int busquedaBinariaInversa(T x, const vector<T>& v, int ini, int fin) {
    if (ini > fin) {
        return -1; // Caso base: elemento no encontrado.
    }

    int medio = ini + (fin - ini) / 2;

    if (v[medio] == x) {
        return medio; // Elemento encontrado
    }

    if (v[medio] < x) { // La lógica se invierte porque el vector es descendente
        return busquedaBinariaInversa(x, v, ini, medio - 1);
    } else {
        return busquedaBinariaInversa(x, v, medio + 1, fin);
    }
}


/**
 * @brief Función de partición para QuickSort. Reordena el vector alrededor de un pivote.
 * @return El índice final del pivote.
 */
template <typename T>
int partition(vector<T>& v, int ini, int fin) {
    T pivote = v[fin];
    int i = ini;

    for (int j = ini; j < fin; j++) {
        if (v[j] <= pivote) {
            swap(v[i], v[j]); // swap es más simple que usar una variable auxiliar
            i++;
        }
    }
    swap(v[i], v[fin]);
    return i;
}

/**
 * @brief Ordena un vector usando el algoritmo QuickSort.
 * @param v Vector a ordenar.
 * @param ini Índice de inicio.
 * @param fin Índice de fin.
 */
template <typename T>
void quickSort(vector<T>& v, int ini, int fin) {
    if (ini < fin) {
        int pivote = partition(v, ini, fin);
        quickSort(v, ini, pivote - 1); // Ordenar sub-vector izquierdo
        quickSort(v, pivote + 1, fin); // Ordenar sub-vector derecho
    }
}

/**
 * @brief Imprime los elementos de un vector en una línea.
 */
template <typename T>
void imprimirVector(const vector<T>& v) {
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }
    cout << endl;
}

#endif // DYV_H