/*Algorithm:
Step-1: Start
Step-2: Input(A,B)
Step-3: Initialise all the elements of matrix C with 0
Step-4: If size<=2, Directly multiply the matrices using strassen formula
Step-5: Else Size=size/2 and use divide and conquer
Step-6: Print the marix C
Step-7: End
*/

#include<iostream>

using namespace std;

int strassen(int *A,int *B,int *C,int n,int m){
	if(m<=2){
		int P=(*A+*(A+n+1))*(*B+*(B+n+1));
        int Q=(*(A+n)+*(A+n+1))*(*B);  
        int R=(*A)*(*(B+1)-*(B+n+1)); 
        int S=(*(A+n+1))*(*(B+n)-*B);   
        int T=(*A+*(A+1))*(*(B+n+1));   
        int U=(*(A+n)-*A)*(*B+*(B+1));  
        int V=(*(A+1)-*(A+n+1))*(*(B+n)+*(B+n+1));  
        *C=*C+P+S-T+V; 
        *(C+1)=*(C+1)+R+T;  
        *(C+n)=*(C+n)+Q+S; 
        *(C+n+1)=*(C+n+1)+P+R-Q+U;
	}
	else{
		m=m/2;
        strassen(A,B,C,n,m)+strassen(A+m,B+m*n,C,n,m);
        strassen(A,B+m,C+m,n,m)+strassen(A+m,B+m*(n+1),C+m,n,m);
        strassen(A+m*n,B,C+m*n,n,m)+strassen(A+m*(n+1),B+m*n,C+m*n,n,m);
		strassen(A+m*n,B+m,C+m*(n+1),n,m)+strassen(A+m*(n+1),B+m*(n+1),C+m*(n+1),n,m);
	}
}

int main(){
	int n;
	cout<<"Enter the size of the matrix. It should be in power of 2: ";
	cin>>n;
	int A[n][n],B[n][n],C[n][n];
	cout<<"\nEnter the elements for matrix-1: "<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>A[i][j];
	cout<<"\nEnter the elements for matrix-2: "<<endl;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>B[i][j];
	cout<<"\nMatrix-1: "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		cout<<A[i][j]<<" ";
	cout<<endl;
	}
	cout<<"\nMatrix-2: "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		cout<<B[i][j]<<" ";
	cout<<endl;
	}
	for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=0;
	strassen(*A,*B,*C,n,n);
	cout<<"\nMatrix after multiplication: "<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)
		cout<<C[i][j]<<" ";
	cout<<endl;
	}
}
