#include <iostream>
#include <stack>
using namespace std;

int main(int argc, char *argv[]) {
	stack <int> S;
	S.push(4);
	S.push(6);
	S.push(5);
	S.push(3);
	cout<<"top: "<<S.top()<<endl;
	
	stack<int> Saux;
	Saux.push(S.top());S.pop();
	Saux.push(S.top());S.pop();
	S.pop();
	
	S.push(Saux.top());Saux.pop();
	S.push(Saux.top());Saux.pop();
	
	while (!S.empty()){
		cout<<"Top: "<<S.top()<<endl;
		S.pop();
	}
	
	return 0;
}

