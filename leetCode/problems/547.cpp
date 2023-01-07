#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
void bfsTraversal(int row, int col, 
	vector<vector<int>> &vis,
	vector<vector<int>> &grid)
{
	vis[row][col]=1;
	queue<pair<int,int>> q;
	
  q.push({row,col});
  while (!q.empty()){
  	int row = q.front().first;
  	int col = q.front().second;
  	q.pop();
    for (int delrow=-1; delrow<=1; delrow++){
		  for(int delcol=-1; delcol<=1; delcol++){
		  	int nRow = row + delrow;
		  	int nCol = col + delcol;
		  	if(nrow>=0 && n< n 
		    && ncol>=0 && ncol<m 
		    && grid[nRow][nCol]==1
		  	&& !visited[nRow][nCol]){
		  		visited[nRow][nCol]=1;
		  		q.push({nRow,nCol});
		  	 }
		  }    
     }
    }
  }
  int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        int m= isConnected[0].size();
        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(m,0));
        for (int row = 0; row < n; row++){
        	for(int col=0; col<m; col++){
        		if(!visited[row][col] && isConnected[row][col]==1){
        			ans++;
        			bfsTraversal(row,col,visited,isConnected)
        		}
        	}
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    Solution sol;
    vector<vector<int>> adjMat;
    for (int i = 0; i < isConnected.size(); i++)
    {
        for (int j = 0; j < isConnected[i].size(); j++)
        {
            if (isConnected[i][j] == 1)
            {
                adjMat[i][j] = 1;
            }
        }
    }
    cout << "ANS: " + sol.findCircleNum(isConnected) << endl;
}
