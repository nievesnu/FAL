//Nieves Núñez Ugena
//A55
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// Explicación del algoritmo utilizado



// Coste del algoritmo utilizado: lineal


// La función recibe un vector con las alturas de los edificios, y la altura de la nave que realizará el rescate
// Devuelve las posiciones de inicio y fin del segmento máximo encontrado.

std::vector<int> resolver(std::vector<int> v, int n, int l, int& secMax, int& longTram) {

    std::vector<int> solucion;
    int i = n - 1, cont = 1, max = 0;
    while (i >= 0) {
        max = std::max(v[i], max);
        if (i > 0 && v[i] == v[i - 1] && max <= v[i]) cont++;
        else {
            if (cont >= secMax && cont >= l) secMax = cont;
            if (cont >= l) {
                longTram++;
                solucion.push_back(i + (cont - 1));
            }
            cont = 1;
        }
        i--;
    }

    return solucion;
}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida

bool resuelveCaso() {
    if (!std::cin)
        return false;

    //leer datos de entrada
    int n = 0, l;
    int i = 0, aux;
    int secMax = 0, longTram = 0;
    std::cin >> n >> l;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) std::cin >> v[i];
    if (n==0)
    {
        return false;
    }
    //llamada a resolver
    auto solucion = resolver(v, n, l, secMax, longTram); 

    //salida del problema
    std::cout << secMax << " " << longTram << " ";
    for (int j = 0; j < solucion.size(); j++) std::cout << solucion[j] << " ";
    std::cout << "\n";

    return true;
}
int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("14sample.in");
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