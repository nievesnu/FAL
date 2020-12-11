// Nieves Núñez
// A55


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int complementario(int n) {
	if (n <10)
	{
		return 9 - n;
	}
	else
	{
		return complementario(n / 10) * 10 + (9 - n % 10);
	}
}

struct solucion {
	int num;
	int aux;
};

solucion inverso(int m) {
	solucion sol;
	if (m < 10) {
		sol.num = complementario(m);
		sol.aux = 1;
	}
	else {
		sol = inverso(m / 10);
		sol.aux *= 10;
		sol.num += (complementario(m) % 10) * sol.aux;
	}
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
	// leer los datos de la entrada
	int num;
	std::cin >> num;

	int sol = complementario(num);
	std::cout << sol << " ";

	solucion inv = inverso(num);
	std::cout << inv.num << "\n";

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("25sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i){
		resuelveCaso();
	}

	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}