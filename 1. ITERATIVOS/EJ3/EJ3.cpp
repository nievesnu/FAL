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
/*hacemos un struct para la solucion y el num de datos, lo metemos en el for para recorrer uno a uno cada vector y 
si hay un nuevo minimo sumamos los datos acomulados, si es el mismo se incrementa n para saber cuantas veces se ha repetido 
y si no se suma e incrementa datos.*/
// Coste del algoritmo utilizado: coste lineal O(n)

// Función que resuelve el problema
struct sol {
    int suma = 0;
    int datos = 0;
};
// Recibe un vector con los datos
// Devuelve suma de los valores y número de sumandos de la suma 
    sol resolver(std::vector<int> const&v) {
    // Inicialización de variables
    sol s;
    int n, aux, min;
    // Codigo del alumno
    min = v[0];
    aux = min;
    n = 1;
    for (int i = 1; i < v.size(); ++i) {
        
        // Aqui el código del alumno
        // No deben hacerse más bucles
        aux = min;
        min = std::min(min, v[i]);
        if (min != aux) //nuevo minimo
        {
            s.suma += aux*n;
            s.datos+=n;
            n = 1;

        }
        else  if (min == v[i])//mismo minimo que coincide con el que leemoa
        {
            n++;
        }
        else
        {
            s.suma+= v[i];
            s.datos++;
        }
    }
    return s;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de los datos
    int numElem;
    std::cin >> numElem;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamar a la función resolver
    sol s = resolver(v);
    // Escribir los resultados
    std::cout << s.suma << ' ' << s.datos << '\n';
}

int main() {
    // Para la entrada por fichero. Comentar para mandar a acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("03sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();

    // Para restablecer entrada. Comentar para mandar a acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
