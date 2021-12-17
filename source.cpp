// Nombre del alumno ..... Mariana Villar Rojas
// Usuario del Juez ...... A77


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Coste de la solucion implementada. Se debe justificar indicando 
// la recurrencia y desplegandola 
/*
* Coste de cada función recursiva
*
* T(n) = c0     n == 0 || n == 1 siendo n el tamaño del vector
* T(n) = T(n/2) + c1      n > 1
*
* Despliegue: T(n) = T(n/2) + c1
*				   = T(n/2^2) + 2 * c1
*				   = T(n/2^3) + 3 * c1
*				   =...=
*				   = T(n/2^K) + k * c1
*
* n/2^K = 1   k = log n
*            T(n) = T(1) + log n * c1 => O(log n) siendo n el tamaño del vector
*/


// función que resuelve el problema
int resolver(std::vector<int> const &v, int num, int ini, int fin) {
	if (ini >= fin) return -1;
	if (ini + 1 == fin && v[ini] == num + ini) return v[ini];
	if (ini + 1 == fin && v[ini] != num + ini) return -1;
	else {
		int m = (ini + fin - 1) / 2;

		if (v[m] == num + m) return v[m];
		else if (v[m] > num + m) return resolver(v, num, ini, m + 1);
		else return resolver(v, num, m + 1, fin);
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
	int num, tam, aux;
	std::vector<int> v;
	std::cin >> tam >> num;

	for (int i = 0; i < tam; i++) {
		std::cin >> aux;
		v.push_back(aux);
	}
    
	int sol = resolver(v, num, 0, v.size());
    // escribir sol
	if (sol != -1)
		std::cout << sol << std::endl;
	else
		std::cout << "NO" << std::endl;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample-35.1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}