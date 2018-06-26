#include<iostream>
using namespace std;
#define max 5
struct node{
	int data;
	int noofchild;
	struct node * children[max];
};

class Tree{
	struct node * root;
	public:
		Tree(){
			root = NULL;
		}
		
		void createtree(int *a , int n){
			root = new struct node;
			root ->data = a[0];
			insertnode(root , a , n);
		}
		void insertnode(struct node * t, int * a ,int  n){
			int child ;
			static int s =1;
			cout<<"Enter the no. of children of "<<t->data<<endl;
			cin>>child;
			t->noofchild = child;
			for(int i = 0; i< child; i++){
				t->children[i] = new struct node;
				t->children[i]->data = a[s++];
			}
			for(int i = 0 ; i<child; i++){
				insertnode(t->children[i] , a , n);
			}
			
		}
		
		void printpre(){
			cout<<"Preorder"<<endl;
			printnodepre(root);
		}
		
		void printnodepre(struct node *t){
			if(t == NULL){
				return;
			}
			cout<<"Data: "<<t->data<<"\t";
			for(int i = 0; i<t->noofchild; i++){
				printnodepre(t->children[i]);
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
	tr.printpre();
}
