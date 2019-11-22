#include <iostream>
#include <list>
using namespace std;
void merge(list<int> &L1, list<int> &L2, list<int>& L){

	list<int>::iterator it1 = L1.begin();
	list<int>::iterator it2 = L2.begin();


	while(it1 != L1.end() and it2 !=L2.end()){
		if(*it1<=*it2){
			L.push_back(*it1);
			it1++;
		}
		else if(*it1>*it2) {
			L.push_back(*it2);
			it2++;
		}
		
	}
	if (it1 == L1.end() and it2 != L2.end()) L.insert(L.end(),it2,L2.end());
	if (it1 != L1.end() and it2 == L2.end()) L.insert(L.end(),it1,L1.end());
	


}

int main() {
	
	list<int> L1 = {1, 3, 6, 11};
	list<int> L2 = {2, 4, 6, 10};
	list<int> L;

	merge(L1,L2,L);
	for (auto i:L){
		cout<<i<<" ";
	}
	return 0;
}







