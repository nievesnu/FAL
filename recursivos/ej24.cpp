//LUIS POZAS PALOMO - EDA - (R01)
#include <iostream>
using namespace std;

long long int eliminarPar(long long int n) {
	long long int num = 0;
	if (n < 10) {
		if (n % 10 % 2 != 0) {
			return n;
		}
	}
	else {
		if (n % 10 % 2 != 0) {
			num = (eliminarPar(n / 10) * 10) + (n % 10);
		}
		else {
			return eliminarPar(n / 10);
		}
	}
	return num;
}



bool resuelveCaso() {
	long long int n;
	cin >> n;

	if (!cin) return false;
	else {
		cout << eliminarPar(n) << endl;
		return true;
	}
}

int main() {
	 // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("24sample.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
