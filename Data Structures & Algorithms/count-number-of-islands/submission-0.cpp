class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int rows[],int cols[],int row,int col){
        visited[row][col]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<4;i++){
            int nrow=row+rows[i];
            int ncol=col+cols[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(grid,visited,rows,cols,nrow,ncol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int rows[]={-1,0,0,+1};
        int cols[]={0,-1,+1,0};
        int count=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(grid,visited,rows,cols,i,j);
                }
            }
        }
        return count;
    }
};
