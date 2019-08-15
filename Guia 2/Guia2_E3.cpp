#include <iostream>
#include <iomanip>
#include <list>
using namespace std;
/*Concatena. Escriba procedimientos para concatenar: a) dos listas L1 y L2 usando insert; b) una
lista LL de n sublistas usando insert; c) una lista LL de n sublistas usando splice. Cada
procedimiento debe retornar el resultado en una lista nueva.
*/
list <int> concatena_a (list<int> &L1,list<int> &L2){
	list<int> L3;
//	for(auto i = L1.begin();i!=L1.end();i++){
//		L3.insert(L3.end(),*i);
//		
//	}
//	for(auto i = L2.begin();i!=L2.end();i++){
//		L3.insert(L3.end(),*i);
//		
//	}
	L3.insert(L3.end(),L1.begin(),L1.end());
	L3.insert(L3.end(),L2.begin(),L2.end());
	return L3;
}

list<int> concatena_b (list<list <int>> &LL){
//	for(auto i=LL.begin();i!=LL.end();i++){
//		for(auto j=i->begin();j!=i->end();j++){
//			
//		}
//	}
	list<list<int>>::iterator it  =LL.begin();
	list<int> L;
	while(it!=LL.end()){
		list<int> &Laux = *it;
		L.insert(L.end(),Laux.begin(),Laux.end());
		
		it++;
		
	}
	
	
	
	return L;
}
list<int> concatena_c (list<list <int>> &LL){
	list<list<int>>::iterator it  =LL.begin();
	list<int> L;
	while(it!=LL.end()){
		list<int> &Laux = *it;
		L.splice(L.end(),Laux);
		
		it++;
		
	}
	
	
	
	return L;
}


int main(int argc, char *argv[]) {
	
	list<int> L1 {1,3,7}; 
	list<int> L2 {9,12};
	list <int> L3 = concatena_a(L1,L2);
	
	list<list<int>> LL {{1,3},{2,6},{2,4}};
	

	
	return 0;
}


