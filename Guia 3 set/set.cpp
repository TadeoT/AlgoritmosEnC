#include <iostream>
#include <set>
#include <btree.hpp>
#include <make_random.hpp>
#include <graphviz.hpp>
#include <iomanip>
#include <lisp.hpp>
using namespace aed;
using namespace std;

/*
1) listarABB. Programe una funcion void listar_ABB(btree<int> &BT) que muestre en orden
ascendente los elementos del conjunto implementado como ABB.
2) insertaABB. Programe una funcion void inserta_ABB(btree<int> &BT, int v) que inserte v
en la posicion adecuada de BT que permita la construccion de un arbol binario de busqueda.
3) eliminaABB. Programe una funcion void elimina_ABB(btree<int> &BT, int v) que elimina,
si existe, el valor v del arbol binario BT de tal manera de preservar el ordenamiento del mismo.
*/

void listar_ABB(btree<int> &BT,btree<int>::iterator it){
	if(BT.end() == it) return;
	
	listar_ABB(BT,it.left());
	cout<<*it<<",";
	listar_ABB(BT,it.right());
	
	
}

void listar_ABB(btree<int> &BT){
	if(BT.begin()==BT.end())return;
	
	listar_ABB(BT,BT.begin());
	
}
void insertar_ABB(btree<int> &BT,btree<int>::iterator it,int num){
	
	if(BT.end() == it){
		it = BT.insert(it,num);
		return;
	}
	
	if(*it == num) return;
	
	if(num<*it){
	insertar_ABB(BT,it.left(),num);
	}
	if(num>*it){
	insertar_ABB(BT,it.right(),num);
	}
	
	
}
void insertar_ABB(btree<int> &BT, int num){
	if(BT.begin()==BT.end())return;
	
	insertar_ABB(BT,BT.begin(),num);
}
void eliminar_ABB(btree<int> &BT){
	
}




void P (set<int> S,set<set<int>> &PS, set<int> AUX,int k ){
	if(AUX.size() == unsigned(k)){
		PS.insert(AUX);
		return;
	}
	
	if(S.size()<(k-AUX.size())) {
		return;
	}
	int elem = *S.begin();
	S.erase(S.begin());
	P(S,PS,AUX,k);
	AUX.insert(elem);
	P(S,PS,AUX,k);
	
	
}
void P(set<int> S,set<set<int>> &PS,int k){
	set<int> AUX;
	P(S,PS,AUX,k);
}


	
void set_union(set<int> &A, set<int> &B,set<int> &U){
	for (auto &a:A){
		U.insert(a);
	}
	for (auto &b:B){
		U.insert(b);
	}
}
void set_intersection(set<int> &A, set<int> &B,set<int> &I){
	for(auto &a:A){
		if(B.count(a)){
			I.insert(a);
		}
	}
}
void set_difference(set<int> &A, set<int> &B,set<int> &D){
	for(auto &a:A){
		if(!B.count(a)){
			D.insert(a);
		}
	}
}


void show(set<int> &S){
	cout<<"{";
	for (auto i:S){
		cout<<i<<" ";
	}
	cout<<"}"<<endl;
}
void show(set<set<int>> &S){
	cout<<"["<<endl;
	for(auto j:S){
		cout<<"{";
		for (auto i:j){
			cout<<i<<" ";
			}
		cout<<"}"<<endl;
		}
	cout<<"]"<<endl;
}

int main() {
	
	btree<int> T;
	lisp2btree("(15(8(3 1 .)(11))(22 17 29))",T);
	insertar_ABB(T,4);
	btree2dot(T);
	listar_ABB(T);
	
	
	return 0;
}







