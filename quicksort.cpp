/*
Algorithm:
Step-1: Start
Step-2: input(n,a[n])
Step-3: Make any element as pivot
Step-4 Partition the array on the basis of pivot
Step-5 Apply quick sort on left partition recursively
Step-6 Apply quick sort on right partition recursively
Step-7: End
*/
#include<iostream> 
using namespace std; 

void swap(int* e1, int* e2) 
{ 
	int temp= *e1; 
	*e1=*e2; 
	*e2=temp; 
} 

int divide(int a[],int p,int r) 
{ 
	int pivot=a[r];
	int i=p-1;
	for (int j=p;j<=r-1;j++){
		if(a[j]<pivot){
			i++;
			swap(&a[i],&a[j]); 
		} 
	} 
	swap(&a[i+1],&a[r]); 
	return i+1; 
} 

void quicksort(int a[],int p,int r) 
{ 
	if(p<r){
		int index=divide(a,p,r); 
		quicksort(a,p,index-1); 
		quicksort(a,index+1,r); 
	} 
} 

int main() 
{ 
	int n;
	cout<<"Enter the no. of elements: ";
	cin>>n;
	int a[n];
	cout<<"Enter the elements: "<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	cout<<"Unsorted array: "; 
	for (int i=0;i<n;i++) 
		cout<<a[i]<<" "; 
	quicksort(a,0,n-1);
	cout<<"\nSorted array: "; 
	for (int i=0;i<n;i++) 
		cout<<a[i]<<" "; 
} 


