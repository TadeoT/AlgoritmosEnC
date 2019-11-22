#include <iostream>
#include <graphviz.hpp>
#include <map>
#include <list>
using namespace aed;
using namespace std;
/* Camino. Implemente la funcion bool es_camino(map<int,list<int>> G, list<int> &L) que
recibe una lista L y determina si es o no camino en el grafo G. El grafo se representa como un
mapa que relaciona cada vertice (clave) con la lista de sus vertices adyacentes (valor).
*/


typedef map<int,list<int>> GRAFO;

bool es_camino(GRAFO &G, list<int> &L){
	if(G.empty()) return false;
	
	list<int>::iterator itL = L.begin();
	GRAFO::iterator it = G.find(*itL);
	itL++;
	bool flag = false;
	list<int> adyacentes;
	int nextNodo=0;
	while(itL!=L.end()){
		flag=false;
		adyacentes = it->second;
		for(auto ady:adyacentes){
			if(ady == *itL){
				nextNodo = ady;
				flag=true;
			}
		}
		
		if(flag){
			itL++;
			it = G.find(nextNodo);
		}
		else {
		return false;
		}
		
		
		
	}
	return true;
}


int main() {
	
	GRAFO G = {{1,{2,4}},
			{2,{1,3,5}},
			{3,{2}},
			{4,{1,5}},
			{5,{2,4}}};
	
	list<int> L = {1,4,5,3};
	//graph2dot(G);
	
	cout<<es_camino(G,L);
	return 0;
}







