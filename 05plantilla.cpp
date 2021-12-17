// Nombre y apellidos del alumno
// Usuario del juez de clase

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

using namespace std;

// Explicación del algoritmo utilizado
/*
tengo una variable que utilizo para guardarme el mayor de los que he recorrido, ya que si comparo un elemento posterior del vector con este
significa que es mayor que todos los que ya hemos recorrido, por lo que para ese valor cumple la condicion

si se el caso de que un elemento es mayor que ese mayor, incrementamos el año y lo gurdamos en el vector a devolver 
(además de actualizar el nuevo mayor)
si no se da solo pasamos de año
*/

// Coste del algoritmo utilizado
//O(n) siendo n el tamaño del vector


// Función que resuelve el problema
// Recibe un vector con los datos
// Devuelve suma de los valores y número de sumandos de la suma
vector<int> resolver(const vector<int> &v, int anyo1) {
    // Inicialización de variables
	vector<int> sol;
	int mayorAnt = v[0];
    // Codigo del alumno
    
    for (int i = 1; i < v.size(); ++i) {
        
        // Aqui el código del alumno
        // No deben hacerse más bucles
		if (v[i] > mayorAnt) {
			anyo1++;
			sol.push_back(anyo1);
			mayorAnt = v[i];
		}
		else {
			anyo1++;
		}
		
        
    }
	return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de los datos
	int anyo1, anyo2;
    cin >> anyo1 >> anyo2;
	vector<int> v(anyo2 - anyo1 + 1);
    for (int& i : v) cin >> i;
    // LLamar a la función resolver
	vector<int> sol = resolver(v, anyo1);
	// Escribir los resultados
	if (!sol.empty()) {
		cout << sol[0];
		for (int i = 1; i < sol.size(); ++i)
			cout << ' ' << sol[i];
	}
	cout << '\n';
}

int main() {
    // Para la entrada por fichero. Comentar para mandar a acepta el reto
#ifndef DOMJUDGE
    ifstream in("05sample.in");
    auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
 
    int numCasos;
  cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    
    // Para restablecer entrada. Comentar para mandar a acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
