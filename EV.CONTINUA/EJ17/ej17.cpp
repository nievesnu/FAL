//*****************
// IMPORTANTE
//
// Nieves Núñez Ugena
// A55
// Usuario del juez de examen que has utilizado en la prueba de hoy
//
//***************************************************

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>


//*******************************
// Aqui especificación de la función que resuelve el problema. 
//
//
//
// Aqui la justificación del coste de la función que resuelve el problema
// 
// 
// 
//*******************************

struct pisos
{
    std::string nombre;
    int altura=0;
    int libre;
};

// Aqui la función implementada por el alumno
std::vector<std::string> resolver(std::vector <pisos> const &v) {
    int mayor = -1; 
    std::vector <std::string> solucion;
    for (int i = v.size()-1; i >= 0; i--)
    {   
        if (v[i].libre!=-1 && v[i].libre>mayor)
        {
            solucion.push_back(v[i].nombre);
        } 
        mayor = std::max(mayor, v[i].altura);
    }

    return solucion;
}

bool resuelveCaso() {
    int numEdificios;
    std::cin >> numEdificios;
    if (numEdificios == 0) return false;

    // Lectura del resto de los datos
    std::vector<pisos> pss(numEdificios);
   for (int i = 0; i < numEdificios; i++)
   {
       std::cin >> pss[i].nombre >> pss[i].altura >> pss[i].libre;
   }  

    // LLamada a la funcion que resuelve el problema

   auto res = resolver(pss);

    // Escribir el resultado
   if (res.size()!=0)
   {
       std::cout << res.size() << std::endl;
   }
   for (int i = 0; i < res.size(); i++)
   {
      std::cout << res[i] << " ";   
   }
   
   if (res.size() == 0) std::cout << "Ninguno ";
   
   std::cout << "\n";

    return true;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("17sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso());

    // Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
