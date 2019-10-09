#include <iostream>
#include <map>
#include <list>
#include <graphviz.hpp>
#include <algorithm>
using namespace aed;
using namespace std;
/*void comp_conexa(map<int,list<int>> &G,list<int> &C, map<int,bool> &visitados,int vertice){
	C.push_back(vertice);
	visitados[vertice];
	list<int> adyacentes = G[vertice];
	for(auto ady : adyacentes){
		if(visitados.find(ady)==visitados.end())
			comp_conexa(G,C,visitados,ady);
		
	}
}

void compconexa(map<int,list<int>> &G,list<list<int>> &L){
	if(G.empty()) return;
	
	map<int,bool> visitados;
	int N = G.size();
	while(visitados.size()<N){
		
		int vertice;
		for(auto v:G){
			if(visitados.find(v.first)==visitados.end()){
				vertice = v.first;
				break;
			}
		}
		
		list<int> C;
		comp_conexa(G,C,visitados,vertice);
		
		L.push_back(C);
	}
	
	
}
void sub_distancia(map<int,list<int>> &G,list<int>hijos,map<int,bool> visitados,int vertice){
	C.push_back(vertice);
	visitados[vertice];
	list<int> hijos = G[vertice];
	for(auto hijo : hijos){
		if(visitados.find(ady)==visitados.end())
			comp_conexa(G,C,visitados,ady);
		
	
}
void distancia (map<int,list<int>> &G,list<list<int>> capas,int verticePartida){
	map<int,bool> visitados;
	
}
	

bool es_vecino(map<int,list<int>>::iterator &q,int sig){
	list<int> &L = q->second;
	auto it = L.begin();
	while (it!=L.end()){
		if(*it == sig){
			return true;
		}
		it++;
	}
	return false;
	
}

bool es_camino(map<int,list<int>> &G, list<int> &L){
	if (L.begin()==L.end()) return false;
	auto it = L.begin();
	if (G.find(*it) == G.end()) return false;
	auto itG = G.find(*it);
	it++;
	while (it!=L.end()){
		if(! es_vecino(itG,*(it))) return false;
		itG=G.find(*it);
		it++;
	}
	return true;
}
*/
void comp_conexa(map<int,list<int>> &G,list<int> &C, map<int,bool> &visitados,int vertice){
	C.push_back(vertice);
	visitados[vertice];
	list<int> adyacentes = G[vertice];
	for(auto ady:adyacentes){
		if(visitados.find(ady)==visitados.end()){
		comp_conexa(G,C,visitados,ady);
		}
	}
}


void comp_conexas (map<int,list<int>> &G,list<list<int>> &L){
	if(G.empty())return;
	map<int,bool> visitados;
	int N = G.size();
	
	while(visitados.size()<N){
		
		int vertice;
		for (auto v:G){
			if(visitados.find(v.first)==visitados.end()){
				vertice = (v.first);
				break;
			}
		}
			
			list<int> C;
			comp_conexa(G,C,visitados,vertice);
			L.push_back(C);
		}
	}
	
map<int,list<int>> colorear (map<int,list<int>> &G){
	map<int,list<int>> resultado;
	map<int,bool> coloreado;
	
	int cantidadNodos = G.size();
	int iColor = 0;
	bool seColoreo = false;
	
	while(coloreado.size()<cantidadNodos){
		for(auto nodo:G){
			if(coloreado.find(nodo.first) == coloreado.end()){
				for(auto vecino:nodo.second){
					if(find(resultado[iColor].begin(),resultado[iColor].end(),vecino)!=resultado[iColor].end()){
						seColoreo=true;
						break;
					}
				}
				if(!seColoreo){
				coloreado[nodo.first];
				resultado[iColor].push_back(nodo.first);
				}
				seColoreo=false;
			}
		}
		
		iColor++;
	}
	
	return resultado;
	
}
	
int main() {
	map<int,list<int>> G{{1,{2,4,5,7}},
						{3,{4,6,7}},
						{4,{1,3,5,6}},
						{5,{1,2,4}},
						{6,{3,4,7}},
						{7,{1,3,6}}};
	map<int,list<int>> L;
	
	graph2dot(G);
	L = colorear(G);
	//comp_conexas(G,L);
	//cout<<"es vecino : "<<es_camino(G,L);
	/*distancia(G,L);
	*/
	for (auto l:L){
		cout<<"Color: "<<l.first<<" : ";
		for(auto i:l.second){
			cout<<i<<", ";
		}
		cout<<endl;
	}
	
	
	return 0;
}







