#include <iostream>
#include <forward_list>
#include <algorithm>
#include <list>
using namespace std;

void selection_sort(list<int> &L){
	auto iOrdenado=L.begin(); 	
	while(iOrdenado!=L.end()){
		auto iMin= min_element(iOrdenado,L.end());
		swap(*iOrdenado,*iMin);
		iOrdenado++;
	}
}

int main(int argc, char *argv[]) {
	list<int> L {5,2,15,9};
	selection_sort(L);
	for(auto x:L)
		cout<<x<<endl;
	return 0;
}

