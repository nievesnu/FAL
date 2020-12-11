// Nieves Núñez Ugena
// A55

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <climits>

// Explicación del algoritmo utilizado
/* n numero de elementos, p numero de corte(¿?), m valor que se esta leyendo, al principio inicialicé el maximo a 0 y va bien pero no
tiene en cuenta números negativos, y al inicializar el minimo a 0 siempre coge 0, y busqué la solución del INT_MAX/MIN porque con el maximo
siempre puede haber un número negativo y con el mínimo si lo inicializo a un numero grande (por ej. a 1000), siempre hay uno superior
para el que no se cumple (1001).
Con el algoritmo simplemente coge el max del lado izq y el min del lado derecho y al final los compara para saber si esta mal dividido */
// Coste del algoritmo utilizado: El coste es O(N) en el caso peor, cuantos mas elementos p == n-1 mas rapido es pues menos elementos procesa

    
bool resolver() {
    // Declaración de variables
    int n, p, maximo=INT_MIN, minimo=INT_MAX, m;
    // Codigo del alumno
    std::cin >> n >> p;
    
    if (p == n - 1) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Se queda en la primera linea
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Saltamos la linea de valores que no queremos leer
        return true;
    }
    //string s;
    //std::getline(cin, s); %igual que el ignore pero declarando un string.

    for (int i = 0; i < n; i++)
    {
        std::cin >> m;
        if (i <= p)
        {
           maximo = std::max(maximo, m);
        }
        else
        {
            minimo = std::min(minimo, m);
        }
            
    }
    if (maximo < minimo)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Funcion que lee de la entrada, resuelve el problema y escribe la salida
void resuelveCaso() {
    if (resolver())
        std::cout << "SI\n";
    else
        std::cout << "NO\n";

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample-02.1.in");
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