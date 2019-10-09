#include <iostream>
#include <map>
#include <list>
using namespace std;


/*bool areinverser(map<int,int> &M1, map<int,int> &M2){
	if(M1.size()!=M2.size()) return false;
	auto itm1 = M1.begin();
	
	while(itm1 != M1.end()){
		auto itaux = M2.find(itm1->second);
		if(itaux==M2.end()){
			return false;
		}
		if(itaux->first != itm1->second){
			return false; 
		}
		itm1++;
	}
	return true;
}
*/

/*void cutoffmap (map<int,list<int>> &M, int p,int q){
	auto it = M.begin();
	while(it!=M.end()){
			
			if((it->first)<p || ((it->first)>=q)){
				it = M.erase(it);
			}
			else{
				list<int> &L = it->second;
				
				auto itL = L.begin();
				while (itL != L.end()){
					
					if((*itL<p) || (*itL>=q)){
						itL = L.erase(itL);
					}else{
					itL++;
					}
				}
				if(L.empty()) it=M.erase(it);
				else {it++;}
			}
	}
}
*/
typedef map<int,list<int>> graph;

bool es_camino(graph &G, list<int> c){
	
	auto it = c.begin();
	while (it!=c.end()){
		auto itaux = G.find(*it);
		if(itaux==G.end())return false;
			list<int> L = it->second;
			auto itL = L.begin();
			while (itL!=L.end()){
				
			}
		}
		it++;
	}
	
	
}

int main(int argc, char *argv[]) {
	list<int> m5{2,3,4}; list<int> m2 {6,7,8};list<int> m3 {4,5};list<int> m4 {1,3,7};
	map<int,list<int>> M = {{1,m5},{5,m2},{8,m3},{3,m4}};
	//map<int,int> M1 = M;
		//map<int,int> M2 = {{2,1},{1,3},{20,8}};
	
	cutoffmap(M,1,6);
	
	return 0;
}

