#include <cstddef>
template<typename T>
class lista {
private:
	class cell{
		friend class lista;
		friend class iterator_t;
		T elem;
		cell *next;
		cell():next (NULL){};
	};
	class iterator{
	private:
		friend class lista;
		cell *ptr;
		iterator (): ptr(NULL){};	
	public:
		T & operator * (){ return ptr->next->elem;}
		T * operator -> (){ return & ptr->next->elem;}
		iterator operator ++ (){ ptr = ptr->next; return *this;}
		bool operator == (iterator p) {return ptr == p.ptr;}
		bool operator != (iterator p) {return ptr != p.ptr;}
	};
private:
	cell *first, *last;

public:
	lista(): first(new cell), last(first){};
	~lista(){ clear(), delete first;}
	T retrieve(iterator p){return p->next->elem;}
	iterator next(iterator p){return p->next;}
	iterator prev(iterator p){
		iterator q = begin();
		while(q->next!=p){
			q = q->next;
		}
		return q;
	}
	iterator insert(iterator p, T x){
		iterator q = p->next;
		cell c = new cell;
		p->next = c;
		c->next = q;
		c->elem = x;

		if(q == NULL) last = c;
		return p;
	}

	iterator begin(){return first;}
	iterator end(){return last;}
	iterator erase(iterator p){
		if(p->next==NULL) last = p;
		iterator q = p->next;
		p->next = q->next;
		delete q;
		return p;
	}
	iterator erase(iterator p, iterator q){
		if(p==q) return p;
		iterator s,r = p->next;
		while( r != q->next){
			s = r->next;
			delete r;
			r = s;
		}
		return p;
	}
	void clear(){erase (begin(),end());}




};

int main(){
	
	lista<int> nueva;
	
	
	
	return 0;
}
