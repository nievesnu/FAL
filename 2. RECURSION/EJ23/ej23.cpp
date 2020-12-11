//Nieves Núñez 
//A55

#include <iostream>
#include <iomanip>
#include <fstream>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado


int resuelve(long long int n) {
    // Aqui codigo del estudiante
    if (n < 10)
        return 1;
    else
        return 1 + resuelve(n / 10);
}

// Entrada y salida de datos
bool resuelveCaso() {
    // Lectura de los datos de entrada
    long long int n;
    std::cin >> n;
    if (!std::cin) return false;

    std::cout << resuelve(n) << std::endl;
    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("23sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
