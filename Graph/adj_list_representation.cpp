#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int n){
	for(int i = 0; i < n; i ++){
		cout << "Adjacency list of the vertex " << i << "\nHead ";
		for(auto it : adj[i])
			cout << " -> " << it;
		cout << endl;
	}
}

int main(){
	int n = 5;
	vector<int> adj[5];

	addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);

	printGraph(adj, n);
}