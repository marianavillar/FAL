
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
// La lógica que he utilizado es comparar el mayor elemento a la izquierda de p (incluyendo p), con el menor elemento a la derecha de p,
//ya que esto significaría que TODOS los de la izquierda son menores que TODOS los de la derecha.
// Creo una función que el llamada en resolver caso, la cual recibe el vector y p, y se encarga de determinar si dicho vector está bien dividido o no.

// Coste del algoritmo utilizado
//coste O(n) siendo n el número de elementos del vector

bool bienDividido(const std::vector<int> &v, int p);

// Funcion que lee de la entrada y llama a una axiliar que resuelve el problema
void resuelveCaso() {

    int n, p;
    std::cin >> n >> p;
    // Declaración de variables
    // Codigo del alumno
	std::vector<int> v(n);
    
	for (int & x : v ) std :: cin >> x;
    
    // llamada a la función auxiliar y resultado
	if (bienDividido(v, p)) std::cout << "SI" << std::endl;
	else std::cout << "NO" << std::endl; 
}

//coste O(n) siendo n el número de elementos del vector
bool bienDividido(const std::vector<int> &v, int p) {
	bool ok = false;

	//primera mitad del vector
	int maximoIzq = v[0]; 

	for (int i = 1; i <= p; i++) { //una vez salimos de este for tenemos el mayor número de la izquierda de p
		if (v[i] > maximoIzq) maximoIzq = v[i];
	}

	//segunda mitad del vector (en caso de que p no esté en la última posición del vector)
	if (p + 1 != v.size()) {
		int minimoDer = v[p + 1];

		for (int i = p + 2; i < v.size(); i++) { //una vez salimos de este for tenemos el menor número de la derecha de p
			if (v[i] < minimoDer) minimoDer = v[i];
		}

		if (maximoIzq < minimoDer) { // si se cumple que el mayor TODOS los de la izq es menor que el menor de TODOS los de la derecha
			ok = true;				// entonces se cumple
		}
	}
	else { // si p está en la última posición del vector, se cumple (dicho en el enunciado)
		ok = true;
	}

	return ok;
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("02sample.in");
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
