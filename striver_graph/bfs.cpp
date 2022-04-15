#include <vector>
#include <iostream>
#include <queue>
using namespace std;


void print_bfs(int n, vector<int> graph[]){
	vector<int> store_bfs;
	vector<int> vis(n+1, 0);
	
	// try for all nodes
	for(int i=0; i<n+1; i++){
		if(vis[i] == 0){
			// perform bfs from this node
			// push the current node
			queue<int> q;
			q.push(i);
			vis[i] = 1;

			// while the queue is not empty, there are unexplored neighbours 
			while(!q.empty()){
				int node = q.front();
				// as front does not remove the element
				q.pop();
				// store in store_bfs
				store_bfs.push_back(node);
				
				// add all unexplored neighbours to the queue
				for(auto j: graph[node]){
					if(vis[j] == 0){
						q.push(j);
						vis[j] = 1;
					}
				} 	
			}
		}	
	}
	
	// print out the contents of store_bfs
	for(auto c: store_bfs){
		cout << c << " ";
	}
	cout << endl; 
}


int main(){
	int n = 6;
	vector<int> graph[n+1];
    graph[1] = {2,3,5};
    graph[2] = {1,4,3};
    graph[3] = {2,1,4,5};
    graph[4] = {2,3};
    graph[5] = {1,3};
	
	print_bfs(n, graph); 
}
