#include<iostream>
using namespace std;

struct node{
	int data;
	struct node *left;
	struct node * right;
};

class Tree{
	struct node * root;
	struct node * temp1;
	struct node * temp2;
	struct node *del;
	struct node *parentofdel;
	struct node *parentofchoice;
	int flag = 0;
	public:
	Tree(){
		root = NULL;
		temp1 = new struct node ;
		temp2 = new struct node; 
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
	
	void deletenode(int t){
		del = new struct node;
		flag = 0;
		inorder(root , t);
//		struct node *choice = new struct node;
		if(isLeaf(temp1)){
			//choice = temp1;
			FindParent(root , del , temp1);
			
			if(!compare(del->left , temp1)){
				temp1->left = del->left;
			}
			else{
				temp1->left = NULL;
			}
			
			if(!compare(del->right , temp1)){
				temp1->right = del->right;
			}
			else{
				temp1->right = NULL;
			}
			
			if(compare(parentofdel->left , del)){
				parentofdel->left = temp1;
			}
			else{
				parentofdel->right = temp1;
			}
			if(compare(parentofchoice->left , temp1)){
				parentofchoice->left = NULL;
			}
			else{
				parentofchoice->right = NULL;
			}
	//		cout<<"del " <<parentofdel->data<<endl;
	//		cout<<"choice "<<parentofchoice->data<<endl;
		}
		else if(isLeaf(temp2)){
			//choice = temp2;
		}
		else if(temp1->right == NULL){
			
		}
		else if(temp2->left == NULL){
			
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
	
	bool compare(struct node * n1, struct node *n2){
		if(n1 == NULL || n2 == NULL){
			return  false;
		}
		if(n1->data == n2->data && n1->left == n2->left && n1->right == n2->right){
			return true;
		}
		return false;
	}
	
	struct node*  FindParent(struct node *n , struct node * find1 , struct node * find2){
		if(n == NULL){
			return 0;
		}	

		FindParent(n->left , find1 , find2);

		if(compare(n->left , find1) || compare(n->right , find1)){
			parentofdel = n;
			//cout<<"n"<<n->data<<"  parent"<<parent->data;
		}
		else if(compare(n->left , find2) || compare(n->right , find2)){
			parentofchoice = n;
			//cout<<"n"<<n->data<<"  parent"<<parent->data;
		}
		FindParent(n->right, find1 , find2);
	}
	void inorder(struct node *n, int t ){
		if(n == NULL){
			return;
		}
	
		inorder(n->left , t);
		//cout<<"Data = "<< n->data<<endl;
		if(flag == 0){
			if(n->data == t){
				del = n;
				flag = 1;
			}
			else{
				temp1 = n;
			}
		}
		else if(flag == 1){
			temp2 = n;
			flag = -1;
		}
		
		inorder(n->right , t);
	}
	

	
	void display(){
		displaynode(root);
	//	inorder(root , 3);
	}
	
	void displaynode(struct node *n){
		if(n == NULL){
			return;
		}
		cout<<"Data = "<< n->data<<endl;
		displaynode(n->left);
		
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
	tr.deletenode(5);
	tr.display();
}
