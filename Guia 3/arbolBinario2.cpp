#include <iostream>
#include <btree.hpp>
#include <make_random.hpp>
#include <graphviz.hpp>
using namespace aed;
using namespace std;

int cant_nodos_prof(btree<int> &A, btree<int>::iterator it, int prof,int profActual){
	int n = 0;
	if(it==A.end()) return 0;
	if(profActual>=prof) {
		n++;
		cout<<*it<<" ";
	}
	
		n += cant_nodos_prof(A,it.left(),prof,profActual+1);
		n += cant_nodos_prof(A,it.right(),prof,profActual+1);
	
	return n;
}

int cant_nodos_prof(btree<int> &A, int prof){
	int cantidad=0;
	cantidad = cant_nodos_prof(A,A.begin(),prof,0);
	return cantidad;
}

int main() {
	
	btree<int> T;
	make_random_btree (T,1);
	btree2dot(T);
	int prof = cant_nodos_prof(T,1);
	cout<<prof<<endl;
	return 0;
}







