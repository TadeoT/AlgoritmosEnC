#include <iostream>
#include <list>
using namespace std;
/*
  BasicSort. Escribir una funcion void basic_sort(list<int> &L)
  que ordena los elementos de L
	de menor a mayor. Para ello emplear el siguiente algoritmo simple:
	utilizando una lista auxiliar L2,
	tomar el menor elemento de L,
	eliminarlo de L e insertarlo al nal de L2 hasta que L este vaca.
	 Luego insertar los elementos de L2 en L
*/
auto iMenor(list<int> &L){
	list<int>::iterator iMenor = L.begin();
	for(auto i = L.begin();i!=L.end();i++){
		if(*i<*iMenor){
			iMenor=i;
		}
	}
	return iMenor;
}
void basic_short(list<int> &L){
	list<int> L2;
	while(L.begin()!=L.end()){
		auto it = iMenor(L);
		L2.push_back(*it);
		L.erase(it);
	}
	L=L2;
	
	
}

int main(int argc, char *argv[]) {
	list <int> L {3,1,7,10,2,4,3,6,12,52,25};
	basic_short(L);
	for(auto i=L.begin();i!=L.end();i++){
		cout<<*i<<endl;
	}
	int stop,stop2;
	cin>>stop;
	cout<<"Prueba "<<stop<<endl;
	cin>>stop2;
	return 0;
}

