#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/**
	No extra stack data structure used, just pure program stack
*/

void dfs(int i, vector<int> &vis, vector<int> &store_dfs, vector<int> graph[]){
	// first store node in store_dfs and mark as visited
	store_dfs.push_back(i);
	vis[i] = 1;
	
	// iterate over all the adjacent nodes and call dfs if not visited
	for(auto j: graph[i]){
		if(vis[j] == 0){
			dfs(j, vis, store_dfs, graph); 
		}
	}	
}

void print_dfs(int n, vector<int> graph[]){
	// keep track of visited index
	vector<int> vis(n+1, 0);
	vector<int> store_dfs;
	// no stack needed, use the recursion stack to make sure all nodes are visited
	
	for(int i=0; i<n+1; i++){
		if(vis[i] == 0){
			// this approach will help iterate over even the components
			// in case of disconnected graph 
			dfs(i, vis, store_dfs, graph);
		}
	}
	
	// print the dfs traversal
	for(auto i: store_dfs){
		cout << i << " ";  
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
	
	print_dfs(n, graph);

}
