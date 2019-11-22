#include <iostream>
#include <btree.hpp>
#include <lisp.hpp>
#include <algorithm>
using namespace aed;
using namespace std;
void make_heap(btree<int> &T,btree<int>::iterator it){
	if (it==T.end()) return;
	make_heap(T,it.left());
	make_heap(T,it.right());
	btree<int>::iterator itAux;
	
	if(it.left()!=T.end() and it.right()!=T.end()){
		if(*it.left()<=*it.right()) itAux = it.left();
		else itAux = it.right();
	}
	if(it.left()==T.end() and it.right() != T.end()) itAux = it.right();
	if(it.right()==T.end() and it.left() !=T.end()) itAux = it.left();
	if(itAux==T.end()) return;
	
	if(*it>*itAux){
		int aux = *it;
		*it = *itAux;
		*itAux = aux;
	}
	
}
void make_heap(btree<int> &T) {
	make_heap(T,T.begin());
	
}

int main() {
	btree<int> T;
	lisp2btree("(5(3 2 1)(2 1 0))",T);
	make_heap(T);
	return 0;
}







