/*
	W9L1
	9.2.1
	Floyad Warshall Algorithm


	Given is the adjacency matrix of an edge-weighted graph, find the shortest distance between every pair of vertices. Use Floyd Warshall Algorithm is for solving the All-Pairs Shortest Path problem. 
	Reference: Floyd Warshal Algorithm.
*/





#include <bits/stdc++.h>
using namespace std;
#define N 5

void display(int n, int dist[][N]){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
}

void floydWarshall(int n, int graph[][N]){
	int dist[N][N], i, j, k;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			dist[i][j] = graph[i][j];
	for (k = 0; k < n; k++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (dist[i][j] > (dist[i][k] + dist[k][j])&& (dist[k][j] != 99999 && dist[i][k] != 99999))
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	display(n, dist);
}



int main(){
    int n; cin>>n;
	
	int graph[N][N];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>graph[i][j];
        }
    }
	floydWarshall(n ,graph);
	return 0;
}
