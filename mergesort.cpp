#include<iostream>
using namespace std;

void mergesort(int *a, int f, int l , int n);

int main(){
	int n;
	cout<<"Enter n"<<endl;
	cin>>n;
	int a[n];
	for(int i = 0; i<n ; i++){
		cin>>a[i];
	}
	mergesort(a, 0 , n-1, n);
	cout<<"The array is"<<endl;
	for(int i=0; i<n; i++){
		cout<<a[i]<<"\t";
	}
}

void mergesort(int *a , int f , int l , int n){
	if(f>=l){
		return;
	}
	mergesort(a , f, (l+f)/2 , n);
	mergesort(a , (l+f)/2+1 , l , n);
	int i =f , j = (l+f)/2  + 1;
	int mid = (l+f)/2;
	int k =f;
	int t[100];
	
	while(i <= mid && j <= l){
		if(a[i] < a[j]){
			t[k] = a[i];
			k++; 
			i++;
		}
		else{
			t[k++] = a[j++];
		}
		
	}
	while(i<=mid){
		t[k++] = a[i++];
	}
	while(j <= l){
		t[k++] = a[j++];
	}

	for(int c = f; c<=l; c++){
		a[c] = t[c];
	}
	
}











