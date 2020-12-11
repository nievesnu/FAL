
// Nieves N��ez
// A55

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicaci�n del algoritmo utilizado



// Coste del algoritmo utilizado



// La funci�n recibe un vector con las alturas de los edificios, y la altura de la nave que realizar� el rescate
// Devuelve las posiciones de inicio y fin del segmento m�ximo encontrado.

void resolver(std::vector<int> const& v, int alturaNave, int& posIni, int& posFin){

// Codigo del alumno
    int maxLong = 0, newMax = 0; //la maxima longitud y si hay una nueva
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i]> alturaNave)
        {
            newMax++;
            if (maxLong < newMax)
            {
                maxLong = newMax;
                posFin = i;
                posIni = i - newMax + 1;
            }
        }
        else
        {
            newMax = 0;
        }
    }

}

// Funcion que lee de la entrada, 
// LLama a la funci�n que resuelve el problema
// Escribe la salida
void resuelveCaso() {
    // Lectura de los datos de entrada
    int numElem, alturaNave;
    std::cin >> numElem >> alturaNave;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamada a la funci�n resolver
    int p, q;
    resolver(v, alturaNave, p, q);
    // Escribir el resultado
    std::cout << p << ' ' << q << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("11sample.in");
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