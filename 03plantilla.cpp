// Nombre y apellidos del alumno
// Usuario del juez de clase

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

// Explicación del algoritmo utilizado
/*
utilizo una variable para guardarme el menor de los numeros (que al principio es el primero)
otra variable numAux, para guardarme las veces que aparece ese menor (por si luego cambia)
y la variable suma que suma todos los numeros menos el menor
si el numero es mayor que el menor, simplemente lo acumulo en la suma
si es menor que el menor, tengo que actualizar la suma y el numero de numero que sumo, utilizando con esa variable que acumula las veces
que sale el menor
si son iguales, simplemente incremento la variable numAux, que indica que ha aparecido otro menor 
*/

// Coste del algoritmo utilizado
//O(n) siendo n el tamaño del vector


// Función que resuelve el problema
// Recibe un vector con los datos
// Devuelve suma de los valores y número de sumandos de la suma
int resolver(const std::vector<int> &v, int &numSumados) {
    // Inicialización de variables
	int suma = 0, numAux= 1, menor = v[0];
    // Codigo del alumno
    
    for (int i = 1; i < v.size(); ++i) {
        
        // Aqui el código del alumno
        // No deben hacerse más bucles

		if (v[i] > menor) {
			suma += v[i];
			numSumados++;
		}
		else if(v[i] < menor) {
			suma += (menor * numAux);
			menor = v[i];
			numSumados += numAux;
			numAux = 1;
		}
		else {
			numAux++;
		}
        
    }
    return suma;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de los datos
    int numElem, numSumados = 0;
    std::cin >> numElem;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamar a la función resolver
    int s = resolver(v, numSumados);
    // Escribir los resultados
    std::cout << s << ' ' << numSumados << '\n';
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
