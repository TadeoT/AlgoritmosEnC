#include <iostream>
#include <list>
using namespace std;

void junta (list<int> &L, int restriccion){
	int contador1 = 0;
	auto puntero = L.begin();
	int aux = 0;
	for(list<int>::iterator i = L.begin();i!=L.end();i++){
		if(contador1>=restriccion){
			*puntero = aux;
			contador1 = 0;
			aux = 0;
			puntero++;
		}
		
		aux = aux + *i;
		contador1++;
		if(i == (--L.end())){
			*puntero = aux;
			puntero++;
		}
	}
	L.erase(puntero,L.end());
}

int main(int argc, char *argv[]) {
	
	list<int> L {3,4,1,5,6};
	junta(L,L.size());
	for(auto i:L)
		cout<<i<<" ";
	return 0;
}

