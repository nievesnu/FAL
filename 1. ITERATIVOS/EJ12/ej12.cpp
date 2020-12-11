// Nieves Núñez Ugena. 
// A55

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado: coste lineal

using psi = std::pair<char, int>;

// Recibe un vector con los datos de entrada del problema
// Modifica este vetor dejando en las primeras posiciones 
// las cintas azules, luego las verdes y uego las rojas
// NO se puede utilizar sort
// p es la primera posicion de una cinta verde, q es la ultima posicion de una cinta verde
auto particion(std::vector<psi>& v, int& p, int& q) {
    // Aqui codigo del estudiante
    while (p <= q || v[p].first == 'v' || 'a' )
    {
        if (v[p].first == 'a') ++p; // elemento del indice izquierdo correcto
        else if (v[q].first == 'r') --q; // elemento del indice derecho correcto
        else if (v[p].first == 'v' && v[q].first == 'v') {
            ++p;
            std::swap(v[p], v[q]);
            p--;
        }
        else { // Ambos elementos fuera de sitio
            std::swap(v[p], v[q]);
        }
    }
}


// Entrada y salida de datos
bool resuelveCaso() {
    // Lectura de los datos de entrada
    int numCintas;
    std::cin >> numCintas;
    if (!std::cin) return false;
    std::vector<psi> v(numCintas); // nombre y altura
    for (psi& n : v) {
        std::cin >> n.first >> n.second;
    }
    // LLamada a la función paticion
    int p, q;
    particion(v, p, q);
    // Ordena cada parte para la salida de datos
    std::sort(v.begin(), v.begin() + p);//v[i] devuelve resolver y fin es el principio del verde
    std::sort(v.begin() + p, v.begin() + 1 + q); //pr y fn verde
    std::sort(v.begin() + 1 + q, v.end()); //fin verde = inicio, fin = v.size
    // Escribe las cintas azules
    std::cout << "Azules:";
    for (int i = 0; i < p; ++i) {
        std::cout << ' ' << v[i].second;
    }
    std::cout << '\n';
    // Escribe la segunda parte
    std::cout << "Verdes:";
    for (int i = p; i <= q; ++i) {
        std::cout << ' ' << v[i].second;
    }
    std::cout << '\n';
    // Escribe la tercera parte
    std::cout << "Rojas:";
    for (int i = q + 1; i < v.size(); ++i) {
        std::cout << ' ' << v[i].second;
    }
    std::cout << '\n';
    return true;
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("12sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso()) {} //Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
