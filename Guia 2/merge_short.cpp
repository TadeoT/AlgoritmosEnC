#include <iostream>
#include <list>
using namespace std;

void merge_t(list<int> &L1, list<int> &L2, list<int> &L){
	if(L1.empty() && L2.empty()) return;
	if(L2.empty()){
		L.push_back(*L1.begin());
		L1.erase(L1.begin());
		return;
	}
	if(L1.empty()){
		L.push_back(*L2.begin());
		L2.erase(L2.begin());
		return;
	}
	auto it1 = L1.begin();
	auto it2 = L2.begin();
	if(*it1<*it2){
		L.push_back(*it1);
		L1.erase(it1);
	}
	if(*it2<*it1){
		L.push_back(*it2);
		L1.erase(it2);
	}
	
	merge_t(L1,L2,L);
	
}
void mergeshort (list<int> &L){
	if(L.empty()) return;
	if((++L.begin()) == (L.end())) return;
	
	int n = L.size()/2;
	list<int> L1;
	list<int> L2;
	auto it=L.begin();
	advance(it,n);
	L1.splice(L1.begin(),L,L.begin(),it);
	L2.splice(L2.begin(),L,it,L.end());
	
	mergeshort(L1);
	mergeshort(L2);
	merge_t(L1,L2,L);
	
	return;
}


int main(int argc, char *argv[]) {
	list<int> L{3,4,8,2,6,5};
	mergeshort(L);
	for (auto i:L){
		cout<<i<<endl;
	}
	return 0;
}

