// Nombre del estudiante. 
// Usuario del juez.

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado
auto resolver(std::vector<int> v) {






}

// Entrada y salida de datos
bool resuelveCaso() {
    // leer los datos de la entrada
    std::vector<int> v;
    if (!std::cin)
        return false;

    auto sol = resolver(v);

    // escribir sol


    return true;

}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("13sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
