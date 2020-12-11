//Nieves Núñez Ugena
//A55

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado



// Recibe un vector con los datos de entrada del problema
// Debe contar el número de veces que aparece cada valor usando un vector auxiliar.
// Devuelve un vector con los valores que se repiten el número máximo de veces
// para que la función resuelveCaso solo tenga que escribirlos. 
// Si solo hay un valor que se repite el número máximo de veces el vector de salida
// tendrá solo ese valor 
std::vector<int> resolver(std::vector<int> const& v, int maximoValores) {
    // Aqui codigo del estudiante
    int n= 0,m=0;
    std::vector<int> sol;
    std::vector<int> aux(maximoValores + 1, 0);
    for (int i = 0; i < v.size(); i++)
    { 
        aux[v[i]]++; //mete el numero que aparezca en el dado en la posicion i
        n = m;
        m = std::max(m, aux[v[i]]);
        if (n < m) { //Si es mayor metemos el nuevo max
            sol.clear();
            sol.push_back(v[i]);
        }
        else if (aux[v[i]] == m) { //Si igual lo añadimos 
            sol.push_back(v[i]);
        }
    }
    
    return sol;
}

// Entrada y salida de datos
bool resuelveCaso() {
    int numTiradas, valorMax;
    std::cin >> numTiradas >> valorMax;
    if (numTiradas == -1) return false;  // Entrada con centinela
    std::vector<int> v(numTiradas);
    std::vector<int> sol;
    for (int& i : v) std::cin >> i;
    // LLamada a la funcion resolver para calcular los valores que 
    // aparecen más veces

    sol = resolver(v,  valorMax);
    std::sort(sol.begin(), sol.end(), std::greater<int>());//Ordenado la salida de mayor a menor
    // Escribir los valores del vector que ha calculado resolver

    for (int& i : sol) std::cout << i << " ";
    std::cout << std::endl;

    return true;
}

int main() {

#ifndef DOMJUDGE
    std::ifstream in("08sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt    
#endif

    while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}