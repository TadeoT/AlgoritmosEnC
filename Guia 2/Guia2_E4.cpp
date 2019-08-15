#include <iostream>
#include <list>
#include <forward_list>
using namespace std;

/*Invierte. Escribir una funcion void invert(list<int> &L), que invierte el orden de la lista L.
Este algoritmo debe implementarse in place y debe ser O(n). Restriccion: no utilizar el metodo
size().
*/

void invertir(list<int> &L){
	auto itMenor = L.begin();
	auto itMayor = L.end();
	if(itMenor!=itMayor){
		--itMayor;
	}
	
	while(itMenor!=itMayor){
		cout<<"Swap"<<endl;
		swap(*itMenor,*itMayor);
		itMenor++;
		if(itMenor == itMayor)
			break;
		itMayor--;
	}
}

int main(int argc, char *argv[]) {
	list<int> L {1,7,3,4};
	invertir(L);
	for (auto i:L)
		cout<<i<<endl;
	return 0;
}

