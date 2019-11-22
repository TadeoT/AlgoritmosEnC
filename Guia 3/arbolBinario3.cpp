#include <iostream>
#include <btree.hpp>
#include <graphviz.hpp>
#include <lisp.hpp>
using namespace aed;
using namespace std;
bool isBST(btree<int> &T, btree<int>::iterator it){
  
  if(it.left() != T.end()){
    if(*it<=*it.left()) return false;
    if(!isBST(T,it.left()))return false;
  }
  if(it.right() != T.end()){
    if(*it>=*it.right()) return false;
    if(!isBST(T,it.right())) return false;
  }
  return true;
  
  
}

bool isBST(btree<int>&T){
  if(T.begin()==T.end()) return true;
  return isBST(T,T.begin());
  
}
int main() {
	
	btree<int> T ;
    lisp2btree("(24 12 (37 .(43 .(46 43 .))))",T);
	btree2dot(T);
	cout<<isBST(T);
	
	return 0;
}







