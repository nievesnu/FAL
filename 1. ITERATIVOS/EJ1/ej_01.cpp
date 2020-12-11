
// Nieves Núñez Ugena
// A55
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

// Explicación del algoritmo utilizado
/*creo un bool para saber si el nuevo valor es mayor que el maximo antiguo, se hace la funcion max
y dependiendo de cual sea el resultado del booleano inicializamos el contador a 1 (caso maximo nuevo)
o si es el mismo se suma 1 al contador */
// Coste del algoritmo utilizado: O(n)


// Funcion que lee de la entrada, resuelve el problema y escribe la salida
void resuelveCaso() {
    int n, maximo, cont;
    bool oldMAX = false;
    std::cin >> n;
    // Declaración de variables
    //ya están
    // Codigo del alumno
    
    maximo = n;
    cont = 0;
    while (n != 0) {
        
        oldMAX = maximo < n;
        maximo = std::max(maximo, n);

        if (oldMAX)
        {
            cont = 1;
        } 
        else if (maximo == n)
        {
            cont++;
        }      


        std::cin >> n;
    }

    // Escribir el resultado
    // Codigo del alumno
    std::cout << maximo << " " << cont << std::endl;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
