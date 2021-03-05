#include<iostream>
#include<climits>
/*
O(|V||E|)
5 8
0 1 -1 
0 2 4
1 2 3
1 3 2  
1 4 2
3 2 5 
3 1 1 
4 3 -3

7 10
0 1 6
0 2 5
0 3 5
1 4 -1
2 1 -2
2 4 1
3 2 -2
3 5 -1
4 6 3
5 6 3
*/
using namespace std;
void bellman(int** edg,int v){
	int * dist=new int[v];
	for(int i=0;i<v;i++){
		dist[i]=INT_MAX;
	}
	dist[0]=0;
	int times=v-1;
	while(times--){
	for(int i=0;i<v;i++)
		for(int j=0;j<v;j++)
			if(edg[i][j]!=0){
				int path=dist[i]+edg[i][j];
				if(path<dist[j])
					dist[j]=path;
			}
	}
	for(int i=0;i<v;i++)
		cout<<"   "<<i<<"\t   "<<dist[i]<<endl;
}
int main(){
	int v,e;
	cout<<"Enter vertices and edges: ";
	cin>>v>>e;
	int** edg=new int*[v];
	for(int i=0;i<v;i++){
		edg[i]=new int[v];
		for(int j=0;j<v;j++)
			edg[i][j]=0;
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
			cout<<edg[i][j]<<" ";
		cout<<endl;
	}
	cout<<"\nShortest distances from the source vertext 0 \n";
	cout<<"Vertext\tDistance\n";
	bellman(edg,v);
}

