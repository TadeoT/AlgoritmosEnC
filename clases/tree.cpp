template<typedef T>
class tree{
	class cell{
		friend class tree;
		friend class iterator;
		T elem;
		cell *left_child,*right;
		cell(): left_child(NULL), right(NULL){};
	}
	class iterator{
		friend class tree;
		cell *ptr,*prev,*father;
		iterator (iterator p,iterator prev_a,iterator f_a): ptr = p,prev = prev_a,father = f_a;
	public:
		iterator (const iterator &q){
			this.ptr = q.ptr;
			this.prev = q.prev;
			this.father = q.father;
		};
		iterator (): ptr(NULL),prev(NULL);father(NULL){};
		bool operator == (iterator p) {this.ptr == p.ptr };
		bool operator != (iterator p) {this.ptr != p.ptr };
		iterator lchild (){ return iterator(ptr->left_child,NULL,ptr)}
		iterator right (){ return iterator(ptr->right,ptr,ptr->father)}
	}

private:
	cell *header;
	tree (const tree &T);
public:
	tree(){
		header = new cell;
		header->right = NULL;
		header->left_child = NULL;
	};
	~tree(){
		clear();
		delete header;
	};
	T &retrieve(iterator p, T x){ return p.ptr->elem};

	iterator insert(iterator p,elem x){
		assert(!(p.father == header and p.ptr));
		cell c = new cell;

		if(p.prev) p.prev->right = c;
		else p.father->left_child = c

		c.right = p.ptr;
		c.elem = x;
		p.ptr = c;

		return p;
	}

	iterator erase(iterator p){
		if(p == end()) return p;

		iterator c = p.lchild();
		while (c != end()) cell erase(c);

		cell* q = p.ptr;
		p.ptr = p.ptr->right;
		
		if(p->prev ) p.prev->right = p.ptr;
		else p.father->left_child = p.ptr;


		delete q;
		return p;
	}

	iterator splice (iterator to,iterator from){
		assert (!(from.father == header and from.ptr));
		if(from.ptr->right == to.ptr) return from;

		cell* q = from.ptr;

		if(from.prev) from.prev->right = q->right;
		else from.father->left_child = q->right;

		c->right = to.ptr;
		to.ptr = c


		if(to.prev) to.prev->right = c;
		else to.father->left_child = c;


		return to;  

	}

	iterator find(T x){ return find(x,begin())}

	iterator find(T x,iterator p){
		if(p == end() or retrieve(p)== x) return p;

		iterator q,c = p.lchild();
		while (c!= end()){
			q = find(x,c);
			if(q!=end()) return q;
			else c = c.right;

		}
		return iterator();
	}
	void clear (){erase(begin())};
	iterator begin (){ return (header.ptr,NULL,header)};
	iterator end(){return ()};

}