//Nieves Núñez 
//A55
#include <iostream>
#include <iomanip>
#include <fstream>

using ulli = unsigned long long int;

ulli fibonacci(const ulli& n, const ulli& a, const ulli& b) {

	return (n == 0) ? b : fibonacci(n - 1, b, a + b);

}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (!std::cin)

		return false;

	if (n == 0)

		std::cout << "0" << std::endl;

	else if (n == 1)

		std::cout << "1" << std::endl;

	else

		std::cout << fibonacci(n - 1, 0, 1) << std::endl;

	return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("28sample.in");
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