// Nieves Núñez Ugena
// A55

#include <iostream>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado
/*miramos si coinciden los elementos de los vectores y lo metemos en el de la solucion, luego al comparar miramos cual es mayor si v1 o v2 y 
metemos primero el pequeño y luego el mayor, los que quedan por leer se meten directamente*/
// Coste del algoritmo utilizado: Coste lineal O(n)

std::vector<int> resolver(std::vector<int>const& v1, std::vector<int>const& v2) {
    // Declaración de variables
    std::vector<int> sol;
    int n, i = 0, j = 0;
    // Codigo del alumno

    while (i < v1.size() && j < v2.size()) {

        // Aqui codigo del alumno
        if (v1[i] == v2[j])
        {
            n = v1[i];
            sol.push_back(n);
            i++;
            j++;
        }
        else if (v1[i]<v2[j])
        {
            n = v1[i];
            sol.push_back(n);
            i++;
        }
        else
        {
            n = v2[j];
            sol.push_back(n);
            j++;
        }

    }
    while (i < v1.size()) {
        // Aqui codigo del alumno
        n = v1[i];
        sol.push_back(n);
        i++;

    }
    while (j < v2.size()) {
        // Aqui codigo del alumno
        n = v2[j];
        sol.push_back(n);
        j++;

    }
    return sol;
}


void resuelveCaso() {
    // Lectura de los datos de entrada
    int n1, n2;
    std::cin >> n1 >> n2;
    std::vector<int> v1(n1);
    std::vector<int> v2(n2);
    for (int& i : v1) std::cin >> i;
    for (int& j : v2) std::cin >> j;
    // LLamada a la función que resuelve el problema
    std::vector<int> sol = resolver(v1, v2);
    // Escribir los resultados
    if (!sol.empty()) {
        std::cout << sol[0];
        for (int i = 1; i < sol.size(); ++i)
            std::cout << ' ' << sol[i];
    }
    std::cout << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

#ifndef DOMJUDGE
    std::ifstream in("04sample.in");
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
