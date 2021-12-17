
// Nombre y apellidos del alumno
// Usuario del juez de clase

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado



// Coste del algoritmo utilizado



// La función recibe un vector con las alturas de los edificios, y la altura de la nave que realizará el rescate
// Devuelve las posiciones de inicio y fin del segmento máximo encontrado.
void resolver(std::vector<int> const& v, int alturaNave, int & posIni, int& posFin) {

// Codigo del alumno
	int segMax = 0, segActual = 0;

	for (int i = 0; i < v.size(); i++) {

		if (v[i] > alturaNave) {
			segActual++;
		}
		else {
			if (segActual > segMax) {
				segMax = segActual;
				posFin = i - 1;
				posIni = posFin - segMax + 1;
			}
			segActual = 0;
		}
	}

	if (segActual > segMax) {
		posFin = v.size() - 1;
		posIni = posFin - segActual + 1;
	}

}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
void resuelveCaso() {
    // Lectura de los datos de entrada
    int numElem, alturaNave;
    std::cin >> numElem >> alturaNave;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamada a la función resolver
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
