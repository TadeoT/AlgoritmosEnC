#include <iostream>
#include <list>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool inverso( list <char> &L){
	auto it=L.begin();
	stack <char> pila;
	queue <char> cola;
	while(it!=L.end()){
		pila.push(*it);
		cola.push(*it);
		it++;
	}
	while(!pila.empty()){
		if(pila.top() != cola.front())
			return false;
		pila.pop();
		cola.pop();
	}
	return true;
}

int main(int argc, char *argv[]) {
	string ss = "allisimariaavisaasivaairamisilla";
	list<char> Frase (ss.begin(),ss.end());
	bool decision = inverso(Frase);
	cout<<decision;
	
	
	return 0;
}

