// Nieves Núñez 
// A55

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <vector>

// Funcion que resuelve el problema

int resolver(std::vector<int> const& v, int longitud) {
	// Inicializar los valores con el primer intervalo
	int cont = 0, pos = -1, num = 0, max = 0; //declaramos un contador para lasa partes rotas,
	//la posicion donde hay que empezar a arreglar, un auxiliar para comprobar que parte del vector
	// está rota y otro para buscar el mayor lado de rotura

	for (int i = 0; i < longitud; i++)
	{
		if (v[i] == 0)
			cont++;
	}

	if (cont>0)
	{
		pos = 0;
	}
	
	max = cont;

	for (int j = longitud; j < v.size(); j++)
	{

		num = v[j - longitud];
		if (num==0)
		{
			cont--;
		} //miramos el numero anterior si es 0 el contador no lo cuenta

		if (v[j]==0)
		{
			cont++;
		} //si es 0 la valla tiene que ser arreglada y empieza a contar
			
		max = std::max(max, cont); //Calculamos el maximo de el numero que estamos mirando y el mas grande

		if (cont >= max && cont != 0)
		{
			pos = j - longitud + 1;
		} // si es mayor o igual ponemos el pos desde j-longitud
		
	}

	return pos;
}

// Resuelve un caso de prueba, leyendo de la entrada la configuracion y escribiendo la respuesta

bool resuelveCaso() {
	int numMetros, longitudTela;
	std::cin >> numMetros >> longitudTela;
	if (numMetros==0)
	{
		return false;

	} // si la entrada es 0 se acaba el problema
	std::vector<int> v(numMetros); //si no es 0 metemos al vector el numMetros
	for (int&i :v)
	{
		std::cin >> i;
	}
	
	auto sol = resolver(v, longitudTela); //miramos que valores aparecen más veces llamando a resolver

	// Codigo
	if (sol != -1)
		std::cout << sol << std::endl; //escribe la pos donde se empieza a arreglar la valla
	else
		std::cout << "No hace falta" << std::endl; //o no hace falta arreglarla
	
	return true;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("09sample.in");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt    
#endif

	while (resuelveCaso());

#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}