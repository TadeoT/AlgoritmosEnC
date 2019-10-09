#include <iostream>
using namespace std;

int main() {
	int main() {
		map<int,list<int>> G{{1,{2,4,5,7}},
		{3,{4,6,7}},
		{4,{1,3,5,6}},
		{5,{1,2,4}},
		{6,{3,4,7}},
		{7,{1,3,6}}};
		map<int,list<int>> L;
		
		graph2dot(G);
	return 0;
}







