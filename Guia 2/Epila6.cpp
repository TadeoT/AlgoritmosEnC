#include <iostream>
#include <list>
#include <stack>
#include <queue>
using namespace std;
int buscar_mayor(stack <int> s, int k){
	int aux = s.top();
	int p=1, i = 1;
	while(i<=k){
		if(s.top()>aux){
			p = i;
			aux=s.top();
		}
		s.pop();
		i++;
	}
	return p;
}

void invierte(stack <int> &s,int k){
	queue <int> q;
	int i=0;
	while(i<k){
		q.push(s.top());
		s.pop();
		i++;
	}
	while(!q.empty()){
		s.push(q.front());
		q.pop();
	}
}

void pancake_short(stack<int> &s){
	int N = s.size();
	for(int k=N;k>0;k--){
		int i = buscar_mayor(s,k);
		invierte(s,i);
		invierte(s,k);
	}
}


int main(int argc, char *argv[]) {
	stack <int> s;
	list<int> L= {3,1,6,8,4,6,9,2};
	for (int x: L){
		s.push(x);
	}
	pancake_short(s);
	for (int x: L){
		cout<<s.top()<<endl;
		s.pop();
	}
	return 0;
}

