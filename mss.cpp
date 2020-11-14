/*
Algorithm:
Step-1: Start
Step-2: Input(n,a[n])
Step-3: Divide the given array in two halves
Step-4: Return the maximum of step-5,step-6,step-7
Step-5: Maximum subarray sum in left half recursively
Step-6: Maximum subarray sum in right half recursively
Step-7: Maximum subarray sum such that the subarray crosses the midpoint
Step-8: End
*/
#include<iostream>
#include<limits.h>
using namespace std;
#define infinity INT_MIN
int max(int a,int b){
	if(a>b)
		return a;
	else return b;
	
}
int max(int a,int b,int c){
	return max(max(a,b),c);
}
int cross(int A[],int l,int mid,int r){
	int sum=0;
	int l_sum=infinity;
	int r_sum=infinity;
	for(int i=mid;i>=l;i--){
		sum+=A[i];
		if(sum>l_sum)
			l_sum=sum;
	}	
	sum=0;
	for(int i=mid+1;i<=r;i++){
		sum+=A[i];
		if(sum>r_sum)
			r_sum=sum;
	}
	return max(l_sum,l_sum+r_sum,r_sum);
}
int mss(int A[],int l,int r){
	if(l==r) 
     return A[l]; 
	int mid=(l+r)/2;
	return max(mss(A,l,mid),cross(A,l,mid,r),mss(A,mid+1,r));	
}
main(){
	int n;
	cout<<"Enter the size of the elements: ";
	cin>>n;
	int A[n];
	cout<<"Enter elements in the array: ";
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	cout<<"The maximum sum is: "<<mss(A,0,n-1);
}

