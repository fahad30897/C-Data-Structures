#include<iostream>
using namespace std;
#define m 5

struct node{
	int data[m+1];
	int noofdata = 0;
	struct node * links[m+2];
};

class Btree{
	struct node * root;
	public:
		Btree(){
			root = NULL;
		}
		
		bool isLeaf(struct node *n){
			if(n == NULL){
				return false;
			}
			else{
				for(int i = 0 ;i <n->noofdata; i++){
					if(n->links[i] != NULL){
						return false;
					}
				}
			}
			return true;
		}
		void insert(int t){
			if(root == NULL){
				root = new struct node;
				root->data[0] =t;
				root->noofdata++;
				for(int i = 0; i<m; i++){
					root->links[i] = NULL;
				}
			}
			else
			insertdata(root , t);
		}
		
		void insertdata(struct node * n , int t){
			if(isLeaf(n)){
				int i;
				for( i = 0 ;i<n->noofdata; i++){
					if(n->data[i] > t){
						break;
					}
				}
				n->noofdata++;
				for(int j = n->noofdata; j> i; j--){
					int temp = n->data[j];
					n->data[j] = n->data[j-1];
					n->data[j-1] = temp;
				}
				n->data[i] = t;
				restructure(n );
			}
			else{
				int i;
				for(i = 0; i<n->noofdata; i++){
					if(n->data[i] > t){
						break;
					}
				}
				insertdata(n->links[i] , t);
			}
		}
		
		struct node* FindParent(struct node * find){
			struct node * p;
			p = root;
			if(p == find){
				return NULL;
			}
			while(p != NULL){
				int i;
				for( i = 0 ; i<p->noofdata + 1; i++){
					if(p->links[i] == find){
						return p;
					}
				}
				for( i = 0 ; i<p->noofdata; i++){
					if(p->data[i] > find->data[0]){
						break;
					}
				}
				p = p->links[i];
			}
		}
		
		void restructure(struct node * n){
			struct node * parent = NULL;
			if(n->noofdata< m){
				return;
			}
			else{
				parent = FindParent(n);
				struct node * temp1 = new struct node;
				struct node * temp2 = new struct node;
				int i;
				for(i =0 ; i<(m/2); i++){
					temp1->data[i] = n->data[i];
					temp1->links[i] = n->links[i];
					temp1->noofdata++;
				}	
				temp1->links[i] = n->links[i];
				for(i = (m/2)+1; i<n->noofdata; i++){
					temp2->data[(i-(m/2 + 1))] = n->data[i];
					temp2->links[(i-(m/2+ 1))] = n->links[i];
					temp2->noofdata++;
				}
				temp2->links[(i-(m/2 + 1))] = n->links[i];
				if(parent != NULL){
					int j;
					for( j=0; j<parent->noofdata; j++){
						if(parent->data[j] > n->data[m/2])
						break;
					}
					parent->noofdata++;
					for(int k=parent->noofdata; k> j; k--){
						int temp = parent->data[k];
						parent->data[k] = parent ->data[k-1];
						parent->data[k-1] = temp;
					}
					parent->links[parent->noofdata+1] = new struct node;
					for(int k = (parent->noofdata)+1; k>j+1; k--){
						struct node * temp = parent->links[k];
						parent->links[k] = parent->links[k-1];
						parent->links[k-1] = temp;
					}
					parent->links[j] = temp1;
					parent->links[j+1] = temp2;
					parent->data[j] = n->data[m/2];
					restructure(parent);
				}
				else{
					struct node* newroot = new struct node;
					newroot ->data[0]= n->data[m/2];
					newroot->noofdata = 1;
					newroot->links[0] = temp1;
					newroot->links[1] = temp2;
					root = newroot;
				}
			}
		}
		
		void display(){
			if(root== NULL){
				return;
			}
			cout<<"Display:"<<endl;
			displaynode(root);
		}
		
		void displaynode(struct node * n){
			if(n == NULL){
				return;
			}
			for(int i =0 ;i<n->noofdata;i++){
				
				cout<<"Data "<<n->data[i]<<"\t";
			}
			cout<<endl;
			for(int i = 0; i<n->noofdata+1; i++){
				displaynode(n->links[i]);
			}
		}
};

int main(){
	int n ,t ;
	Btree bt;
	cout<<"Enter the number of nodes you want to enter:"<<endl;
	cin>>n;
	cout<<"Enter the values:"<<endl;
	for(int i = 0 ; i<n; i++){
		cin>>t;
		bt.insert(t);
	}
	bt.display();
}
