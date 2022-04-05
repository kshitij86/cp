
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    bool is_valid(int i, int j, vector<vector<int>> &maze){
    	if((i >= 0 && i<=maze.size()-1) && (j>=0 && j<=maze[0].size()-1))
    		return true;
    	return false;
    }
    
    void rat_in_maze(int i, int j, vector<vector<int>> &maze, int visited[5][5], string path, vector<string> &ans){
    	if(is_valid(i, j, maze) && (maze[i][j] == 1) && (!visited[i][j])){
    		visited[i][j] = 1;
    		if(i == maze.size()-1 && j == maze[0].size()-1){
    	        ans.push_back(path);
    			return;
    		}
    		
    		//up
    		path.push_back('U');
    		rat_in_maze(i-1, j, maze, visited, path, ans); 
    		path.pop_back(); 
    
    		//down
    		path.push_back('D');
    		rat_in_maze(i+1, j, maze, visited, path, ans); 
    		path.pop_back();
    
    		//left
    		path.push_back('L');
    		rat_in_maze(i, j-1, maze, visited, path, ans); 
    		path.pop_back(); 
    
    		//right
    		path.push_back('R');
    		rat_in_maze(i, j+1, maze, visited, path, ans); 
    		path.pop_back();
    	}
    }
    
    
    vector<string> findPath(vector<vector<int>> m, int n){
        int visited[5][5] = {{0, 0, 0, 0, 0}}; 
        string path = ""; 
        vector<string> ans; 
        
        rat_in_maze(0, 0, m, visited, path, ans); 
        
        return ans;
        
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends