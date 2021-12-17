// Nombre del estudiante. 
// Usuario del juez.

#include <iostream>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado
/*
Utilizo dos variables i y j para recorrer los vectores v1 y v2
como estan ordenados voy comparando entre el contenido de un vector con el otro, y si es menor el de uno de ellos, lo inserto
con push back en el vector final (podria haberse hecho tambien con una tercera variable como indice de este vector) e incremento el indice 
del vector del cual he insertado su valor en el vector final.
En caso de que este comparando posiciones iguales, solo las inserto una vez, e incremento ambas variables.

los dos ultimos while son para lo mismo, para seguir rellenando si uno de los dos vectores no han llegado al final aún, por lo que
solamente insertamos sus valores e incrementamos su indice.
*/

// Coste del algoritmo utilizado
//O(n) siendo n el tamaño del vector final, es decir, la suma de los tamaños de los dos vectores en el peor de los casos

std::vector<int> resolver(std::vector<int>const& v1, std::vector<int>const& v2) {
    // Declaración de variables
	std::vector<int> sol;
	int i = 0, j = 0;
    // Codigo del alumno
    
    while (i < v1.size() && j < v2.size()) {

        // Aqui codigo del alumno

		if (v1[i] < v2[j]) {
			sol.push_back(v1[i]);
			i++;
		}
		else if (v1[i] == v2[j]) {
			sol.push_back(v1[i]);
			i++;
			j++;
		}
		else {
			sol.push_back(v2[j]);
			j++;
		}

    }
    while (i < v1.size()) {
        // Aqui codigo del alumno
		sol.push_back(v1[i]);
		i++;
        
    }
    while (j < v2.size()) {
        // Aqui codigo del alumno
		sol.push_back(v2[j]);
		j++;
    }
    return sol;
}


void resuelveCaso() {
    // Lectura de los datos de entrada
    int n1, n2; 
    std::cin >> n1 >> n2;
    std::vector<int> v1(n1);
    std::vector<int> v2(n2);
    for (int& i : v1) std::cin >> i;
    for (int & j : v2) std::cin >> j;
    // LLamada a la función que resuelve el problema
    std::vector<int> sol = resolver(v1, v2);
    // Escribir los resultados
    if (!sol.empty()) {
        std::cout << sol[0];
        for (int i = 1; i < sol.size(); ++i) 
            std::cout << ' ' << sol[i];
    }
    std::cout << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto

 #ifndef DOMJUDGE
    std::ifstream in("04sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
 #endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) {
        resuelveCaso();
    }
    
    // Para restablecer entrada. Comentar para acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
