//Input: 0 3 1 5 5 8
//Input: 6 4 2 9 7 9
//Output: A3,A2,A5,A6
/*Algorithm:
Step-1: Start
Step-2: Input(n,at[n],st[n],ft[n])
Step-3: Sort at[],st[] according to ft[]
Step-4: i=0, at[i] selected
Step-5: Repeat step-6 for j=1 and less than n
Step-6: if st[j]>fn[i]
			at[j] selected
			i=j
		j++
Step-7: End
*/

#include<iostream>
using namespace std;
void sort(int st[],int ft[],int at[],int n){
	int temp1,temp2,temp3;
	for(int i=1;i<n;i++){
		for(int j=0;j<n-i;j++)
			if(ft[j]>ft[j+1]){
				temp1=st[j];
				st[j]=st[j+1];
				st[j+1]=temp1;
				temp2=at[j];
				at[j]=at[j+1];
				at[j+1]=temp2;
				temp3=ft[j];
				ft[j]=ft[j+1];
				ft[j+1]=temp3;		
			}
	}
}

void find(int st[],int ft[],int at[],int n){
	int i=0;
	cout<<"A"<<at[i]<<" ";
	for(int j=1;j<n;j++){
		if(st[j]>=ft[i]){
			cout<<"A"<<at[j]<<" ";
			i=j;
		}
	}	
}

int main(){
	int n;
	cout<<"Enter no. of activities: ";
	cin>>n;
	int st[n],ft[n],at[n];
	cout<<"Enter starting time of activities: ";
	for(int i=0;i<n;i++){
		cin>>st[i];
		at[i]=i+1;
	}
	cout<<"Enter finish time of activities: ";
	for(int i=0;i<n;i++){
		cin>>ft[i];
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<"A"<<at[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<st[i]<<"  ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<ft[i]<<"  ";
	}
	sort(st,ft,at,n);
	cout<<"\n\nAfter sorting: "<<endl<<endl;
	for(int i=0;i<n;i++){
		cout<<"A"<<at[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<st[i]<<"  ";
	}
	cout<<endl;
	for(int i=0;i<n;i++){
		cout<<ft[i]<<"  ";
	}
	cout<<"\n\nFollowing activities are selected: "<<endl;
	find(st,ft,at,n);
}
