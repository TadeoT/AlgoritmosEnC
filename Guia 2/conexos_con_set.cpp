#include <iostream>
#include <map>
#include <graphviz.hpp>
#include <list>
#include <set>
using namespace aed;
using namespace std;
void comp_conexa (map<int,list<int>> &G, set<int> &visitados, int vertice, list<int> &C){
	C.push_back(vertice);
	visitados.insert(vertice);
	
	list<int> adyacentes = G[vertice];
	for (auto ady:adyacentes){
		if(visitados.find(ady) == visitados.end()){
			comp_conexa(G,visitados,ady,C);
		}
	}
	
}

void comp_conexas(map<int,list<int>> &G, list<list<int>> &L){
	if (G.empty()) return ;
	int N = G.size();
	set<int> visitados;
	while(visitados.size()<N){
		
		int vertice;
		for(auto v:G){
			if(visitados.find(v.first) == visitados.end()){
				vertice = v.first;
				break;
			}
		}
		
		list<int> C;
		comp_conexa(G,visitados,vertice,C);
		
		L.push_back(C);
		
	}
}

int main() {
	map<int,list<int>> G = {{1,{3,4}},
						{3,{4}},
						{2,{5}},
						{4,{7,1}},
						{5,{2}},
						{7,{4}}};
	
	graph2dot (G);
	list<list<int>> L;
	comp_conexas(G,L);
	
	for(auto i:L){
		cout<<"{ ";
		for(auto x:i){
			cout<<x<<", ";
		}
		cout<<" } "<<endl;
	}
	return 0;
}







