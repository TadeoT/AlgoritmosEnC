#include <iostream>
#include <vector>
#include <set>
using namespace std;
bool esta_incluido(set<int> &v, set<int> &V){
	for (auto n:v){
		if(V.count(n)==0) return false;
	}
	return true;
}
bool cubre_todo(vector<set<int>>&v, set<int>& W){
	for(auto s:v){
		if(!(esta_incluido(s,W))) return false;
	}
	return true;
}

void show(set<int> &S){
	cout<<"{";
	for (auto i = S.begin();i!=S.end();i++){
		cout<<*i;
		if(!(i ==--S.end())) cout<<","; 
	}
	cout<<"}"<<endl;
}
void show(vector<set<int>> &S){
	cout<<"["<<endl;
	for(auto j:S){
		cout<<"{";
		for (auto i:j){
			cout<<i<<" ";
		}
		cout<<"}"<<endl;
	}
	cout<<"]"<<endl;
}

int main() {
	set<int> W = {1,2,3,4,5,6,7,8,9};
	vector<set<int>> v={{1,2,3,4},{3,4,5},{5,6,7,8,9}};
	show(W);
	show(v);
	
	cout<<"Esta incluido : "<<cubre_todo(v,W);
	return 0;
}







