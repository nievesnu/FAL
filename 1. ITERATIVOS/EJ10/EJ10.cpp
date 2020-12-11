// Nieves N��ez
// A55

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicaci�n del algoritmo utilizado
/*creamos un auxiliar y recorremos el vector todos los num_matriculados == v.size y si el numero 
de matricula del alumno puede dividirse entre 2 con cociente 0 metemos dicho v[i] en el vector que 
se utilizar� en la salida*/

// Coste del algoritmo utilizado: El coste de la funcion es lineal 
 
/* Esta funci�n recibe un vector con los n�meros de matricula de los alumnos modifica el vector 
de entrada eliminando los valores impares */

void resolver(std::vector<int>& v) {
    // Codigo del alumno
   int n = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]%2 == 0) //si el numero de la matricula del alumno es divisible entre dos con cociente 0 lo metemos en el vector de salida
        {
            v[n] = v[i];
            n++;
        }
    }
    v.resize(n);
}

// Funcion que lee de la entrada, 
// LLama a la funci�n que resuelve el problema
// Escribe la salida
bool resuelveCaso() {
    // Leer datos de entrada
    int numElem;
    std::cin >> numElem;
    if (numElem == -1) return false;
    std::vector<int> v(numElem);
    for (int i = 0; i < numElem; ++i) {
        std::cin >> v[i];
    }
    // LLamada a la funci�n resolver
    resolver(v);
    // Escribir el vector resultado
    if (v.size() > 0) std::cout << v[0];
    for (int i = 1; i < v.size(); ++i)
        std::cout << ' ' << v[i];
    std::cout << '\n';
    return true;
}

int main() {
    // Para la entrada por fichero. Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("10sample.in");
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