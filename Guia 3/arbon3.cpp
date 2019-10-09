#include <iostream>
#include <graphviz.hpp>
#include <tree.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;

bool odd(int x) {
	return (x%2);
}
bool even(int x){
	return (!(x%2));
}
template<typename F>
int count_if(tree<int> &T,tree<int>::iterator it,F f){
	int c = 0;
	if(f(*it)) c++;
	it= it.lchild();
	while(it!=T.end()){
		c += count_if(T,it,f);
		it++;
	}
	return c;
}
template<typename F>
int count_if(tree<int> &T,F f){
	
	tree<int>::iterator nodo = T.begin();
	if(nodo==T.end()) return 0;
	int c = count_if(T,nodo,f);
	return c;
	
	
	
}


int main() {
	
	tree<int> T;
	lisp2tree("(3 (4 9 (0 2 1)) 7 (8 6))",T);
	
	cout<<"count_if: "<<count_if(T,even);
	
	
	
	
	tree2dot(T);
	
	
	
	return 0;
}







