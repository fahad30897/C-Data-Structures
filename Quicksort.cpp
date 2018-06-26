#include<iostream>
using namespace std;
void Quicksort(int *a, int f , int l , int );

void swap(int i , int j , int *a){
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;	
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i = 0;i<n; i++){
		cin>>a[i];
	}
	Quicksort(a, 0 , n-1 , n);
	cout<<endl;
	cout<<"Array";
	for(int i = 0; i<n; i++){
		cout<<a[i]<<"\t";
	}
}

void Quicksort(int *a, int f , int l , int n ){
	//cout<<"1"<<f<<"\tl"<<l;
	if(f>=l){
		return;
	}
	int pivot = f;
	int i = f;
	int j = l;
	while(j>=i){
		//cout<<"WHile 1";
		while(a[j] >= a[pivot] && j>=i){
			j--;
		}
		if(a[j] < a[pivot] && j> i){
			swap(j , pivot , a);
			pivot = j;
		}
//		cout<<"\nWhile 2"<<i<<"j = "<<j;
		while(a[i]<=a[pivot] && j>=i){
			i++;
		}
		if(a[i] > a[pivot] && j>i){
			swap(i , pivot, a);
			pivot = i;
		}
		cout<<endl;
}
//	cout<<"While out";
	Quicksort(a , f , pivot-1, n );
	Quicksort(a , pivot+1 , l, n );
	//cout<<"4";
}









