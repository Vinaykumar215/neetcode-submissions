class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        int rows[]={-1,0,0,+1};
        int cols[]={0,-1,+1,0};

        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            for(int i=0;i<4;i++){
                int nrow=row+rows[i];
                int ncol=col+cols[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == INT_MAX){
                    grid[nrow][ncol]=grid[row][col]+1;
                    q.push({nrow,ncol});
                }
                
            }
        }
    }
};
