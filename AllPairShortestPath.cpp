#include<iostream>
#include<climits>
#define INF 100000
/*
O(V^3)
4 4
0 1 5
0 3 10
1 2 3
2 3 1
*/
using namespace std;
void AllPairSP(int** edg,int v){
	for(int k=0;k<v;k++)
		for(int i=0;i<v;i++)
			for(int j=0;j<v;j++)
				if((edg[i][k]+edg[k][j])<edg[i][j])  
                    edg[i][j]=edg[i][k]+edg[k][j];
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++)
			if(edg[i][j]==INF)  
                cout<<"INF"<<" ";  
            else
                cout<<" "<<edg[i][j]<<"  ";
		cout<<endl;
	}
}
int main(){
	int v,e;
	cout<<"Enter vertices and edges: ";
	cin>>v>>e;
	int** edg=new int*[v];
	for(int i=0;i<v;i++){
		edg[i]=new int[v];
		for(int j=0;j<v;j++)
			if(i==j)
				edg[i][j]=0;
			else
				edg[i][j]=INF;
	}
	cout<<"\nEdges in the graph: "<<endl;
	cout<<"S D Wt\n";
	for(int i=0;i<e;i++){
		int f,s,distance;
		cin>>f>>s>>distance;
		edg[f][s]=distance;
	}
	cout<<"\nAdjacency matrix: \n";
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++)
		if(edg[i][j]==INF)  
                cout<<"INF"<<" ";  
            else
                cout<<" "<<edg[i][j]<<"  ";
        cout<<endl;
	}
	cout<<"\nAll pair shortest path \n";
	AllPairSP(edg,v);
}
