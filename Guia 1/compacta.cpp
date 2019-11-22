#include <iostream>
#include <list>
using namespace std;
/*
Compacta. Escribir una funcion void compacta(list<int> &L,list<int> &S) que toma un
elemento entero n de S y, si es positivo, saca n elementos de L y los reemplaza por su suma. Esto
ocurre con todos los elementos de S hasta que se acaben, o bien se acaben los elementos de L.
*/

void compacta (list<int> &L, list<int> &S){
	for(auto it = S.begin();it!=S.end();it++){
		if(*it>0){
			auto ij = L.begin();
			int contador = 0;
			int sum = 0;
			while(contador<*it){
				if(ij==L.end()) {
					L.push_back(sum);
					return;
				}
				sum = sum + *ij;
				ij = L.erase(ij);
				contador++;
			}
			L.push_front(sum);
		}
	}
}
void showList(list<int> L){
	for(auto i:L){
		cout<<i<<" ";
	}
	cout<<endl;
}
int main() {
	list<int> L = {1,2,3,4,5};
	list<int> S ={2,2};
	compacta(L,S);
	showList(L);
	return 0;
}







