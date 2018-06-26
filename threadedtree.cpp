#include<iostream>
using namespace std;
#define max 100
struct node{
	int data;
	int isleaf = 0;
	struct node *left;
	struct node * right;
};


class Tree{
	struct node * root;
	struct node * temp;
	public:
	Tree(){
		root = NULL;
		temp = NULL;
	}
	void insert(int t){
		if(root == NULL){
			root = new struct node;
			root ->data = t;
			root->left = NULL;
			root->right = NULL;
		}
		else{
			insertnode(root , t);
		}
	}
	
	void insertnode(struct node *n , int t){
		if( t <= n->data ){
			if(n->left == NULL){
				n->left = new struct node;
				n->left ->data = t;
				n->left ->left = NULL;
				n->left ->right  = NULL;
			}
			else{
				insertnode(n->left, t );
			}
		}
		else{
			if(n->right == NULL){
				n->right = new struct node;
				n->right ->data = t;
				n->right->left = NULL;
				n->right->right = NULL;
			}
			else{
				insertnode(n->right , t);
			}
		}
	}
	
	bool isLeaf(struct node *n){
		if(n == NULL){
			return false;
		}
		if(n->left == NULL && n->right == NULL){
			return true;
		}
		return false;
	}
	
	void threadtree(){
		thread(root);
	}
	void thread(struct node *n){
		if(n==NULL){
			return;
		}
		thread(n->left );
		if(isLeaf(n)){
			n->isleaf = 1;
		}
		thread(n->right );
	}
	
	void displayin(){
		cout<<"inorder"<<endl;
		displaynode(root);
	}
	void displaynode(struct node *n){
		if(n == NULL ){
			return;
		}
		if(n->isleaf == 1){
			cout<<"data  = "<<n->data<<endl;
			return;
		}
		displaynode(n->left);
		cout<<"Data = "<< n->data<<endl;	
		displaynode(n->right);
	}
};

int main(){
	Tree tr;
	int n , temp;
	cin>>n;
	for(int i = 0; i<n;i++){
		cin>>temp;
		tr.insert(temp);
	}
	cout<<endl;
	tr.threadtree();	
	tr.displayin();
}
