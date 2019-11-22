#define USECHRONO
#undef HAVE_MPI
#include "eval.hpp"
#include <cassert>
#include <climits>
#include <cstdlib>
#include <stack>
#include <map>

using namespace aed;
using namespace std;

void make_full(btree<int> &T) {
  // COMPLETAR AQUI...
}
int suma_total(btree<int>&T,btree<int>::iterator it){
  int total = *it;
  if(it.left() != T.end()){
    total += suma_total(T,it.left());
  }
  if(it.right() != T.end()){
    total += suma_total(T,it.right());
  }
  
  return total;
  
  
}
int max_subbtree(btree<int>&T,btree<int>::iterator it){
  int subtotal = INT_MIN;
  subtotal = suma_total(T,it);
  
  int maxSub_izq = INT_MIN;
  if(it.left()!=T.end()){
    maxSub_izq = max_subbtree(T,it.left());
  }
  int maxSub_der = INT_MIN;
  if(it.right()!=T.end()){
    maxSub_der = max_subbtree(T,it.right());
  }
  return max(0,(max(subtotal,max(maxSub_der,maxSub_izq))));
}

int max_subbtree(btree<int>&T){
  if (T.begin()==T.end()) return 0;
  
  return max_subbtree(T,T.begin());
    
  return 0;
}

bool connected(set<int> &s1,set<int> &s2){
  for(auto n:s1){
    if((s2.count(n))) return true;
  }
  return false;
}
int most_connected(vector< set<int> > &VS) {
  int nmax = -1; int jmax;int indice;
  for (int i = 0;i<VS.size();i++){
    jmax =0;
    for(int j=0;j<VS.size();j++){
      if(i==j) continue;
      if(connected(VS[i],VS[j])) jmax++;
    }
    if(jmax >nmax){
      nmax=jmax;
      indice=i;
    }
  }
  return indice;
  
  
  
  return 0;
}

//---:---<*>---:---<*>---:---<*>---:---<*>---:---<*>
int main() {
  Eval ev;
  int vrbs = 0;
  int seed = 123;
  int h1=0,h2=0,h3=0;

  do {

    //ev.eval<1>(make_full,vrbs);
    //h1 = ev.evalr<1>(make_full,seed,vrbs);

    ev.eval<2>(max_subbtree,vrbs);
    h2 = ev.evalr<2>(max_subbtree,seed,vrbs);

    ev.eval<3>(most_connected,vrbs);
    h3 = ev.evalr<3>(most_connected,seed,vrbs);

    printf("S=%03d -> H1=%03d H2=%03d H3=%03d\n",
           seed,h1,h2,h3);
    
    printf("\n\nIngrese un valor para la semilla:");
  } while (cin>>seed);

  return 0;
}
