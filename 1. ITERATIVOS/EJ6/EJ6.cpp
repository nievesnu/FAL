// Nieves Núñez Ugena
// A55
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using lli = long long int;
using vint = std::vector<int>;

// Calcula un vector con los valores acumulados
void resolver(std::vector<lli> const& a, std::vector<lli>& v)
{
    // Aqui codigo del estudiante
    v.push_back(lli(a[0]));
    for (size_t i = 1; i < a.size(); i++)
    {
        v.push_back(lli(a[i]) + v[i - 1]);
    }

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // Lee las dos fechas entre las que tenemos datos
    int a1, a2;
    std::cin >> a1 >> a2;
    if (a1 == 0 && a2 == 0) return false;

    // Lee el resto de los datos y calcula el vector de acumulados
    // Aqui código del estudiante

    int aux;
    std::vector<lli> a;
    std::vector<lli> v;

    for (int i = 0; i < a2 - a1 + 1; i++) {
        std::cin >> aux;
        a.push_back(aux);
    }

    resolver(a, v);

    // Lectura de las preguntas
    int m; std::cin >> m;
    int sol;

    for (int i = 0; i < m; ++i) {
        int f1, f2;
        std::cin >> f1 >> f2;
        // Escribir la respuesta        
        // Aqui codigo del estudiante
        if (f1 - a1 != 0)
            sol = v[f2 - a1] - v[f1 - a1 - 1];
        else
            sol = v[f2 - a1];
        std::cout << sol << std::endl;
    }
    std::cout << "---\n";

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

#ifndef DOMJUDGE
    std::ifstream in("06sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif


    while (resuelveCaso());


#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}