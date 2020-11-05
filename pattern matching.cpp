/*
Algorithm:
Step-1: Start
Step-2: input(original string-st1,sub string-st2)
step-3: l1=length of st1 and l2=length of st2
step-4: for i=0 and less than l1-l2
		for j=0 and less than l2
			checl if st1[i+j]==st2[j]
			if yes, charachter matched
			and j++,i++
			if no, charachter not matched
			i++
Step-5: End
*/
#include<iostream> 
#include<string.h>
using namespace std; 

main(){
	char st1[20],st2[20];
	int i,j,flag=0;
	cout<<"Enter original string: ";  
	cin>>st1;
	cout<<"Enter sub string: "; 
	cin>>st2;
	for(i=0;i<strlen(st1)-strlen(st2);i++){      
		for(j=0;j<strlen(st2);){         
			if(st1[i+j]==st2[j])            
				j++;
			else 
				break;
			if(j>=strlen(st2))
				flag=1;
		}
	if(flag==1)
		break;
	}
	if(flag==1)
		cout<<"Sub string is a pattern of original string";
	else
		cout<<"Sub string is not a pattern of original string";
}
