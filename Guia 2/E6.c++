#include <iostream>
#include <list>
using namespace std;
/*
ReemplazaSecuencia. Dada una lista de enteros L y dos listas SEQ y REEMP, posiblemente de
distintas longitudes, escribir una funcion void reemplaza(list<int> &L, list<int>& SEQ,
list<int> &REEMP), que busca todas las secuencias de SEQ en L y las reemplaza por REEMP. Por
ejemplo, si L=(1,2,3,4,5,1,2,3,4,5,1,2,3,4,5), SEQ=(4,5,1) y REEMP=(9,7,3), entonces
despues de llamar a reemplaza(L,SEQ,REEMP), debe quedar
L=(1,2,3,9,7,3,2,3,9,7,3,2,3,4,5). Para implementar este algoritmo primero buscar desde el
principio la secuencia SEQ, al encontrarla, reemplazar por REEMP, luego seguir buscando a partir
del siguiente elemento al ultimo de REEMP
void
*/
void reemplaza(list<int> &L, list<int>& SEQ,list<int> &REEMP){
	auto principio = L.begin();
	auto i = L.begin();
	auto iSeq = ++SEQ.begin();
	while(i!=L.end()){
		if(*i==*SEQ.begin()){
			principio=i;
		}
		else{
			if (*i==*iSeq){
			iSeq++;
			if(*i==*(--SEQ.end())){
				i=L.erase(principio,++i);
				
			}
			}
		}
		
		
		i++;
	}
}

int main(int argc, char *argv[]) {
	list<int> L {1,2,3,4,5,1,1,2,3,4,5,1};
	list<int> seq {4,5,1};
	list<int> reemp {9,7,3};
	reemplaza(L,seq,reemp);
	for (auto i:L){
		cout<<i<<" ";
	}
	
	return 0;
}

