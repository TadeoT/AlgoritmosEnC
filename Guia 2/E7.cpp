#include <iostream>
#include <list>
using namespace std;

void acendente (list<int> &L,list<list<int>> &LL){
	auto iP = ++L.begin();
	list<int> Laux;
	for (auto i =L.begin();i!=L.end();i++){
		if(*i<*iP){
			Laux.push_back(*i);
			iP++;
		}else{
			Laux.push_back(*i);
			LL.push_back(Laux);
			Laux.erase(Laux.begin(),Laux.end());
			iP++;
		}
	}
}

int main(int argc, char *argv[]) {
	list<int> L {3,7,4,1,5,8,12,9,14};
	list<list<int>> LL;
	acendente(L,LL);
	for(auto i=LL.begin();i!=LL.end();i++){
		cout<<endl;
		for (auto j=i->begin();j!=i->end();j++){
			cout<<*j<<" ";
		}
	}
	
	return 0;
}

