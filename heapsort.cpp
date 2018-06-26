#include<iostream>
using namespace std;

void shiftdown(int *a , int i , int n){
	int temp = i;
	int left = 2*i+1;
	int right = 2*i +2;
	if(left<n){
		temp = left;
		if(right<n && a[right]>a[left]){
			temp = right;	
		}
	}
	if(a[temp] > a[i]){
		int t = a[temp];
		a[temp] = a[i];
		a[i] = t;
	}
	if(temp != i){
		shiftdown(a , temp , n);
	}
}

void buildheap(int * a, int n){
	for(int i = n/2; i>=0; i--){
		shiftdown(a, i , n);
	}
}

void heapsort(int *a, int n){
	int size = n-1;
	while(size>0){
		int t = a[0];
		a[0] = a[size];
		a[size]  = t;
		shiftdown(a, 0 , size);
		size--;
	}
}

int main(){
	int n ;
	cin>>n;
	int a[n];
	for(int i =0 ; i<n; i++){
		cin>>a[i];
	}
	buildheap(a , n);
	cout<<endl;
	heapsort(a , n);
	cout<<endl;
	for(int i = 0; i<n; i++){
		cout<<a[i]<<"\t";
	}
}
