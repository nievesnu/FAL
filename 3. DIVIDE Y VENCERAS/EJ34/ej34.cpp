// Nieves Núñez Ugena
// A55

#include <iostream>
#include <fstream>
#include <vector>

//*******************************
// Explicacion del algoritmo utilizado: una rut para n=1 y otra para n>1
// Coste de la solucion:  O(log(n)) 
//Recurrencia y orden de complejidad
//*******************

// Aqui la funcion recursiva que resuelve el problema
int resolver(std::vector<int> const& v1, int ini, int fin) {
    int m = 0;
    if (ini + 1 == fin) { // vector con 1 elemento
        return v1[ini];
    }
    else
    {
        int m = (ini + fin) / 2;

        if (v1[m] > v1[ini]) return resolver(v1, ini, m);
        else return resolver(v1, m, fin);
    }
}

// Tratar cada caso
bool resuelveCaso() {
    int tam;
    //entrada
    std::cin >> tam;

    if (!std::cin)
        return false;

    std::vector<int> v1(tam);

    for (int i = 0; i < tam; ++i) {
        std::cin >> v1[i];
    }
    //solucion
    auto sol = resolver(v1, 0, tam);

    // escribir sol
    std::cout << sol << "\n";

    return true;
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("34sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
    
    while (resuelveCaso());

    // Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}