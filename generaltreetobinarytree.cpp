#include<iostream>
using namespace std;

#define max 5
struct gnode{
	int data;
	int noofchild;
	struct gnode * children[max];
};

struct bnode{
	int data;
	struct bnode* left;
	struct bnode* right;
};

class binarytree{
	struct bnode *root;
	struct bnode *ptr ;
	public:
		binarytree(){
			root = NULL;
			ptr = NULL;
		}
		void insertroot(int t){
			if(root == NULL){
				root = new struct bnode;
				root->data = t;
				root->left = NULL;
				root->right = NULL;
			}
		}
		struct bnode * returnroot(){
			return root;
		}
		
		void print(){
			printnode(root);
			
		}
		void printnode(struct bnode * n){
			if(n == NULL){
				return;
			}
			cout<<"Data : "<<n->data<<"\t";
			printnode(n->left);
			printnode(n->right);
		}
		
		void getnode(struct gnode * n){
			ptr = NULL;
			searchnode(n , root);
		}
		
		void searchnode(struct gnode *find , struct bnode * t){
			if(t==NULL){
				return;
			}
			if(ptr == NULL){
				if(t ->data == find->data){
					ptr = new struct bnode;
					ptr = t;
				}
			}
			searchnode(find , t->left);
			searchnode(find , t->right);
			
		}
		
		struct bnode * getptr(){
			return ptr;
		}

};
class Tree{
	struct gnode * root;
	public:
		Tree(){
			root = NULL;
		}
		void createtree(int *a , int n){
			root = new struct gnode;
			root ->data = a[0];
			insertgnode(root , a , n);
		}
		void insertgnode(struct gnode * t, int * a ,int  n){
			int child ;
			static int s =1;
			cout<<"Enter the no. of children of "<<t->data<<endl;
			cin>>child;
			t->noofchild = child;
			for(int i = 0; i< child; i++){
				t->children[i] = new struct gnode;
				t->children[i]->data = a[s++];
			}
			for(int i = 0 ; i<child; i++){
				insertgnode(t->children[i] , a , n);
			}
			
		}
		
		void printpre(){
			cout<<"Preorder"<<endl;
			printnodepre(root);
		}
		
		void printnodepre(struct gnode *t){
			if(t == NULL){
				return;
			}
			cout<<"Data: "<<t->data<<"\t";
			for(int i = 0; i<t->noofchild; i++){
				printnodepre(t->children[i]);
			}
		}
		
		binarytree converttobinary(){
			binarytree btree;
			binarytree * ptr = &btree;
			btree.insertroot(root->data);
			convertnode(ptr, root );
			return btree;
		}
		
		void convertnode(binarytree * btree , struct gnode *n){
			struct bnode * broot = btree->returnroot();
			btree->getnode(n);
			struct bnode * temp = btree->getptr();
			int direction = 0;
			
			for(int i = 0 ; i<n->noofchild; i++){
				inserttobtree(temp , n->children[i]->data , direction);
				if(direction == 0 && temp!=NULL){
					temp = temp->left;
				}
				else{
					if(temp!=NULL)
						temp = temp ->right;
				}
				direction = 1;
			}
			for(int i = 0; i<n->noofchild; i++){
				convertnode(btree , n->children[i]);
			}
		}
		
		void inserttobtree(struct bnode * temp , int t , int d){
			if(d == 0){
				temp ->left = new struct bnode;
				temp ->left->data = t;
				temp ->left->left = NULL;
				temp ->left->right = NULL;
			}
			else{
				temp->right = new struct bnode;
				temp->right->left = NULL;
				temp->right->right = NULL;
				temp ->right->data = t;
			}
		}
};

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i =0; i<n; i++){
		cin>>a[i];
	}
	Tree tr;
	tr.createtree(a, n);
	binarytree br = tr.converttobinary();
	br.print();
}	
	

