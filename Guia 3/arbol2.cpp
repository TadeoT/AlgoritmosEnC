#include <iostream>
#include <tree.hpp>
#include <graphviz.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;
typedef tree<int>::iterator nodo_t;

void listarNodos(tree<int> &T){
	list<nodo_t> nivelActual;
	list<nodo_t> nivelSiguiente;
	
	
	nivelActual.push_back(T.begin());
	
	while(!nivelActual.empty()){
		nivelSiguiente.clear();
		for(auto nodo:nivelActual){
			cout<<*nodo<<" ";
			nodo_t hijo = nodo.lchild();
			while(hijo!=T.end()){
				nivelSiguiente.push_back(hijo);
				hijo++;
			}
		}
		nivelActual=nivelSiguiente;
	}
	
}

void impar2(tree<int> &G, tree<int>::iterator &nodo){
	tree<int>::iterator it = nodo.lchild();
	
	while(it!=G.end()){
		if(*it%2) {
			it=G.erase(it);
		}
		else{
			impar2(G,it);
			it++;
		}
	}
}

void impar2(tree<int> &G){
	tree<int>::iterator it = G.begin();
	if (it==G.end()) return;
	if (*it%2) G.erase(it);
	impar2(G,it);
}

bool impar(tree<int> &G,tree<int>::iterator &nodo){
	
	if(*nodo%2) {
		nodo =  G.erase(nodo);
		return true;
	}
	else {
		auto it = nodo.lchild();
		
		while (it!=G.end()){
			bool se_elimino = impar(G,it);
			
			if(!se_elimino) it++;
	}
		return false;
	}
	
	
}
void impar(tree<int> &G){
	
	tree<int>::iterator it = G.begin();
	if(it==G.end()) return;
	impar(G,it);
	
	
}


int main() {
	
	tree<int> T;
	lisp2tree("(4 (3(2(7 8))1) (10 (11 14 15)) 5)",T);
	
	
	/*
	tree<char> T;
	tree<char>::iterator nodo=T.begin();
	
	nodo = T.insert(T.begin(),'h');
	nodo = nodo.lchild();
	nodo = T.insert(nodo,'s');
	T.insert(nodo.lchild(),'t');
	nodo = T.insert(nodo,'j');
	nodo = nodo.lchild();
	nodo = T.insert(nodo,'m');
	T.insert(nodo.lchild(),'p');
	nodo = T.insert(nodo,'k');
	
	
	
	T.erase(T.begin().lchild().lchild().right());
	T.erase(T.begin().lchild().right().lchild());
	*/
	//impar2(T);
	tree2dot(T);
	listarNodos(T);
	
	
	
	
	
	
	
	
	
	
	return 0;
}







