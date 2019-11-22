#include <iostream>
#include <list>
using namespace std;

list<int> max_sublist(list<int> &L){
  int max_suma = 0;
  list<int> Lmax;
  list<int>::iterator it = L.begin();

  while(it!=L.end()){
 	list<int>::iterator it2 = it;
 	list<int> laux;
 	int sum = 0,max_parcial=0;
 	while(it2!=L.end())
 		sum += *it2;
 		if(sum>max_parcial){
 			laux.push_back(*it2);
 		}


int main() {
	list<int> L = {1,2,3,-5,4,-3,2};
	list<int> lmax;
	lmax = max_sublist(L);
	for (auto i:lmax){
		cout<<i<<" ";
	}
	return 0;
}







