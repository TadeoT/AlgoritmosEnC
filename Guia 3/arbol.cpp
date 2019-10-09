#include <iostream>
#include <lisp.hpp>
#include <tree.hpp>
#include <graphviz.hpp>
#include <make_random.hpp>
using namespace aed;
using namespace std;

void prefijo(tree<char> T, tree<char>::iterator it){
	cout<< *it<<", ";
	it=it.lchild();
	while (it != T.end()){
		prefijo(T,it);

	}
}
void postfijo(tree<char> T, tree<char>::iterator it){
	tree<char>::iterator child = it.lchild();
	while (child!=T.end()){
		postfijo(T,child);
		child=child.right();
	}
	cout<< *it<<", ";
}

void postfijo(tree<char> T){
	cout<<"(";
	if(T.begin()==T.end()) return;
	postfijo(T,T.begin());
	cout<<")"<<endl;
}

void prefijo(tree<char> T){
	cout<<"(";
	if(T.begin()==T.end()) return;
	prefijo(T,T.begin());
	cout<<")"<<endl;
}
void cant_hojas(tree<char> T,tree<char>::iterator it,int &hoja){
	it=it.lchild();
	if(it==T.end()){
		hoja++;
	}
	while(it!=T.end()){
		cant_hojas(T,it,hoja);
		it=it.right();
	}
}
int cant_hojas(tree<char> T){
	if(T.begin()==T.end()) return 0;
	int hoja=0;
	cant_hojas(T, T.begin(),hoja);
	return hoja;
}

int altura(tree<int> T,tree<int>::iterator it){
	it=it.lchild();
	int hMax = 0;
	while(it!=T.end()){
		int h = altura(T,it);
		it = it.right();
		if(h>hMax) hMax = h;
		
	}
	return hMax+1;
	
}
int altura(tree<int> T){
	
	tree<int>::iterator it = T.begin();
	if (it==T.end()) return 0;
	
	
	int h = altura(T,it)-1;
	
	return h;
}



void maximo(tree<char> &T,tree<char>::iterator it,char &max){
	if(*it>max) max = *it;
	it = it.lchild();
	while (it!=T.end()){
		maximo(T,it,max);
		it = it.right();
	}
}
char maximo(tree<char> &T){
	tree<char>::iterator it = T.begin();
	if(it==T.end()) return *it;
	char max = *it;
	maximo(T,it,max);
	
	return max;
}

void count_level(tree<int> T,tree<int>::iterator it,int l,int &level,int &cantidad){
	it = it.lchild();
	++level;
	while (it!=T.end()){
		if (level == l) cantidad++;
		count_level(T,it,l,level,cantidad);
		it = it.right();
	}
	--level;
}
int count_level(tree<int> T, int l){
	tree<int>::iterator it = T.begin();
	if(it==T.end()) return 1;
	int cantidad=0;
	int level=0;
	count_level(T,it,l,level,cantidad);
	
	return cantidad;
	
	
}



int main() {
	
	tree<int> T;
	make_random_tree(T,13,5);
	tree2dot(T);
	int nivel = 3;
	
	//prefijo(T);
	//cout<<"La cantidad de hojas es: "<<cant_hojas(T)<<endl;
	cout<<"La altura es : "<<altura(T)<<endl;
	//cout<<"El char mas grande del arbol es :"<<maximo(T)<<endl;
	cout<<"en el nivel "<<nivel<<" hay "<<count_level(T,nivel)<<endl;
	return 0;
}







