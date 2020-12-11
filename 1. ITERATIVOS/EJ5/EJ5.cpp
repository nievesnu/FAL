// Nieves Núñez Ugena
// A55
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>

// Explicación del algoritmo utilizado
// Coste del algoritmo utilizado
/*
Coste lineal O(n)
*/
// Funcion que lee de la entrada, resuelve el problema y escribe la salida
auto resolver(int a1, int a2, std::vector<int> const& ventas) {
    // Declaración de variables
    // Codigo del alumno
    std::vector<int>sol;
    int n = std::max(n, ventas[0]);
    for (int i = 1; i < ventas.size(); i++)
    {
       n = std::max(n, ventas[i-1]);
       if (n<ventas[i])
       {
          sol.push_back(a1+i);
       }       
    }
    
    return sol;
}

void resuelveCaso() {
    int a1;
    int a2;
    std::cin >> a1 >> a2;


    std::vector<int> ventas;
    int num;
    for (int i = 0; i <= a2 - a1; i++)
    {
        std::cin >> num;
        ventas.push_back(num);
    }

    auto v = resolver(a1, a2, ventas);
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("05sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }

    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
