#include <vector>
#include <iostream>
using namespace std;

void graph_printer(int n, vector<pair<int, int>> edges){
	// an  array of n vectors to integer
	vector<int> graph[n+1];
	
	for(int i=0; i<edges.size(); i++){
		// consider this particular pair
		pair<int, int> edge = edges[i];

		// undirected graph so add to both
		graph[edge.first].push_back(edge.second);
		graph[edge.second].push_back(edge.first);
	}
	
	// print the graph
	for(int i=0; i<n+1; i++){
		cout << i << " -> ";
		for(int j=0; j<graph[i].size(); j++){
			cout << graph[i][j];
			if(j != graph[i].size()-1){
				cout <<  ",";			
			}			
		}
		cout << endl;		
	}
	
}

int main(){
	// a graph with 6 vertices
	int n = 6;
	vector<pair<int, int>> edges = {{1,2}, {2,4}, {2,3}, {1,3}, {3,4}, {1,5}, {5,3}};
	
	graph_printer(n, edges);
}