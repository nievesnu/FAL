﻿//Nieves Núñez 
//A55
#include <iostream>
#include <iomanip>
#include <fstream>



struct solucion {
    int num;
    int aux;
};

solucion inverso(int m) {
    solucion sol;
    if (m < 10) {
        sol.num = m;
        sol.aux = 1;
    }
    else {
        sol = inverso(m / 10);
        sol.aux *=10;
        sol.num += (m % 10) *sol.aux;
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int num;
    std::cin >> num;

    if (num == 0) return false;
    solucion inv = inverso(num);
    std::cout << inv.num << "\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("26sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso());


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}