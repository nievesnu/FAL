// Nieves Núñez Ugena
// A55

#include <iostream>
#include <fstream>
#include <vector>

//*******************************
// Explicacion del algoritmo utilizado
// Coste de la solucion. Recurrencia y orden de complejidad
//*******************

// Aqui la funcion recursiva que resuelve el problema
int buscar(std::vector<int> const& v1, std::vector<int> const& v2, int ini, int fin) {
    if (ini == fin) // vector sin elementos
        return v1[ini];
    if (ini + 1 == fin) { // vector con 1 elemento
        if (v1[ini] == v2[ini]) return v1[ini + 1];
        else return v1[ini];
    }
    else
    {
        int m = (ini + fin) / 2;
        if (v1[m] != v2[m]) return buscar(v1, v2, ini, m);
        else return buscar(v1, v2, m, fin);
    }
}

// Tratar cada caso
void resuelveCaso() {
    int num;

    // lectura del vector A
    std::cin >> num;
    std::vector<int> v1(num);
    for (int i = 0; i < num; ++i)
        std::cin >> v1[i];

    // lectura del vector B
    std::vector<int> v2(num - 1);
    for (int j = 0; j < num - 1; ++j)
        std::cin >> v2[j];

    // resolver
    int sol = buscar(v1, v2, 0, v2.size());

    // mostrar resultado
    std::cout << sol << '\n';
}

int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("32sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    int casos;
    std::cin >> casos;
    for (int i = 0; i < casos; ++i)
        resuelveCaso();

    // Para restablecer entrada.
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    //system("PAUSE");
#endif

    return 0;
}