// Nombre del estudiante. Mariana Villar
// Usuario del juez. A77

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


// Explicación del algoritmo utilizado


// Coste del algoritmo utilizado
//


long long int resuelve(std::vector<long long int> & v) {
	int segMax = 0, segMayorAct = 0;
	long long int moda = 0, modaAct = v[0];
	std::sort(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		if (modaAct == v[i]) {
			segMayorAct++;
		}
		else {
			if (segMayorAct > segMax) {
				segMax = segMayorAct;
				moda = modaAct;
			}

			modaAct = v[i];
			segMayorAct = 1;
		}
	}

	if (segMayorAct > segMax) {
		moda = modaAct;
	}
	return moda;
}


// Entrada y salida de datos
bool resuelveCaso() {
    // Lectura de los datos de entrada
    int numAcc;
    std::cin >> numAcc;
    if (numAcc == -1) return false;
    std::vector<long long int> v(numAcc); 
    for (long long int & n : v) {
		std::cin >> n;
    }
    // LLamada a la función resuelve
	long long int m = resuelve(v);

	std::cout << m << std::endl;

    return true;
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("13sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif
    
    while (resuelveCaso()) {} //Resolvemos todos los casos
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif 
    return 0;
}
