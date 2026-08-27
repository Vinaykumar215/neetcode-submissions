class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int nooffreshoranges=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==2){
                    visited[i][j]=1;
                    q.push({{i,j},0});
                }
                if(!visited[i][j] && grid[i][j]==1){
                    nooffreshoranges++;
                }
            }
        }

        int rows[]={-1,0,0,+1};
        int cols[]={0,-1,+1,0};
        int mintime=0;
        int count=0;
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            int row=p.first.first;
            int col=p.first.second;
            int time=p.second;
            mintime=max(mintime,time);
            for(int i=0;i<4;i++){
                int nrow=row+rows[i];
                int ncol=col+cols[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});
                    visited[nrow][ncol]=1;
                    count++;
                }
            }

        }
        if(count != nooffreshoranges) return -1;
        else return mintime;
    }
};
