#include <iostream>
#include <forward_list>
#include <algorithm>
#include <list>
<<<<<<< HEAD
using namespace std;

void selection_sort(list<int> &L){
	auto iOrdenado=L.begin(); 	
	while(iOrdenado!=L.end()){
		auto iMin= min_element(iOrdenado,L.end());
		swap(*iOrdenado,*iMin);
		iOrdenado++;
=======
using namespace std;

void selection_sort(list<int> &L){
	auto iOrdenado=L.begin(); 	
	while(iOrdenado!=L.end()){
		auto iMin= min_element(iOrdenado,L.end());
		swap(*iOrdenado,*iMin);
		iOrdenado++;
>>>>>>> 0e90fd752b98e66f1a28a4d045acf3c75f4e9230
	}
}

int main(int argc, char *argv[]) {
<<<<<<< HEAD
	list<int> L {5,2,15,9};
	selection_sort(L);
	for(auto x:L)
=======
	list<int> L {5,2,15,9};
	selection_sort(L);
	for(auto x:L)
>>>>>>> 0e90fd752b98e66f1a28a4d045acf3c75f4e9230
		cout<<x<<endl;
	return 0;
}

