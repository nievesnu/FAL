//*****************
// IMPORTANTE
//
// Nombre y apellidos del alumno
// Usuario del juez de examen que has utilizado en la prueba de hoy
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>

//*******************************
// Explicacion del algoritmo utilizado
// Coste de la solucion. Recurrencia y orden de complejidad
//*******************

// Aqui la funcion recursiva que resuelve el problema

// Tratar cada caso
void resuelveCaso() {
    int numA;
    // lectura del vector A
    std::cin >> numA;
    std::vector<int> vA(numA);
    for (int i = 0; i < numA; ++i)
        std::cin >> vA[i];
    // lectura del vector B
    std::vector<int> vB(numA-1);
    for (int j = 0; j < numA - 1; ++j)
        std::cin >> vB[j];
    // resolver
    int n = ......
    // mostrar resultado
    std::cout << n << '\n';
    
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("sample.in");
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
