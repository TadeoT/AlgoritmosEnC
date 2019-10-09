#include <iostream>
#include <map>
#include <list>
#include <graphviz.hpp>
#include <tree.hpp>
#include <climits>
using namespace aed;
using namespace std;

struct Edge{
	char a, b;
	int w;
};

minima_arista(map<char,map<char,int>> &G,list<char> agregados){
	Edge edge;
	edge.w = INT_MAX;
	for(char &v:agregados){
		map<char,int> &ady = G[v];
		for(auto p:ady){
			//ver si no forma ciclo
			if(find(agregados.begin(),agregados.end(),p.first) != agregados.end()) continue;
			if (p.second<edge.w){
				edge.w = p.second;
				edge.a = v;
				edge.b = p.first;
			}
			
		}
	}
}

int Prim(map<char,map<char,int>> &G, tree<int> &T){
	int N = G.size();
	int i = 0;
	int W = 0;
	list<char> agregados;
	while(i<N-1){
		
		//seleccionar la arista de menor peso adyacente a alguna ya agregada
		Edge edge = minima_arista(G,agregados);
		//luego agragarla al arbol
		auto it = T.find(edge.a);
		T.inser(it.lchild(),edge.b);
		//acumular el peso total
		w += edge.w
		
		
		
		w += peso_arista_i;
		
		i++;
	}
	return W;
}



int main() {
	
	map<int,list<int>> G = {{1,{4,5,3,7}},
				{3,{1,5,6,7}},
				{5,{1,3,7,6,4}},
				{6,{3,5}},
				{7,{1,3,5}}};

	graph2dot(G);
				
	
	return 0;
}







