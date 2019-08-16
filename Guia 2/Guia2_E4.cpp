#include <iostream>
#include <list>
#include <forward_list>
<<<<<<< HEAD
using namespace std;

/*Invierte. Escribir una funcion void invert(list<int> &L), que invierte el orden de la lista L.
Este algoritmo debe implementarse in place y debe ser O(n). Restriccion: no utilizar el metodo
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
=======
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
>>>>>>> 0e90fd752b98e66f1a28a4d045acf3c75f4e9230
			break;
		itMayor--;
	}
}

int main(int argc, char *argv[]) {
<<<<<<< HEAD
	list<int> L {1,7,3,4};
	invertir(L);
	for (auto i:L)
=======
	list<int> L {1,7,3,4};
	invertir(L);
	for (auto i:L)
>>>>>>> 0e90fd752b98e66f1a28a4d045acf3c75f4e9230
		cout<<i<<endl;
	return 0;
}

