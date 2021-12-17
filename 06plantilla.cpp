
// Nombre y apellidos del estudiante
// Usuario del juez

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using lli = long long int;
// Calcula un vector con los valores acumulados
// Recibe un vector a con los datos de entrada
// Devuelve en un vector diferente v los datos de entrada acumulados
// Postcondicion de la función para todo i: 0 <= i < v.size(): v[i] = Sum k : 0 <= k <= i: a[i]
void resolver(std::vector<int> const& a, std::vector<lli>& v)
{
	lli acum = 0;
   // Aqui codigo del estudiante
	for (int i = 0; i < v.size(); i++) {
		acum += a[i];
		v[i] = acum;
	}

}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // Lee las dos fechas entre las que tenemos datos
    int a1, a2;
    std::cin >> a1 >> a2;
    if (a1 == 0 && a2 == 0) return false;

    // Lee el resto de los datos en un vector

    // Aqui código del estudiante
	std::vector<int> a(a2 - a1 + 1);
	for (int& i : a) std::cin >> i;
    
    // calcula el vector de acumulados llamando a la funcion resolver
    // Aqui código del estudiante
	std::vector<lli> v(a2 - a1 + 1);
	resolver(a, v);

    // Lectura de las preguntas
    int m; std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int f1, f2;
        std::cin >> f1 >> f2;
        // Escribir la respuesta
        // Aqui codigo del estudiante
		if (f1 == a1) {
			std::cout << v[f2 - a1] << std::endl;
		}
		else {
			std::cout << v[f2 - a1] - v[f1 - a1 - 1] << std::endl;
		}
    }
    std::cout << "---\n";

    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    
#ifndef DOMJUDGE
    std::ifstream in("06sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    
    while (resuelveCaso())
        ;
    
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}



