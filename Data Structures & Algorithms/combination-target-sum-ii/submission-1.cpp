class Solution {
public:
    void solve(vector<int>& candidates,int target,vector<int>& ans,vector<vector<int>>& res,int ind,int n){
        if(ind==n){
            if(target==0){
                res.push_back(ans);
            }
            return;
        }
        if(candidates[ind]<=target){
            ans.push_back(candidates[ind]);
            solve(candidates,target-candidates[ind],ans,res,ind+1,n);
            ans.pop_back();
        }
        int next=ind+1;
        while(next<n && candidates[next]==candidates[ind]){
            next++;
        }
        solve(candidates,target,ans,res,next,n);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ans;
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        solve(candidates,target,ans,res,0,candidates.size());
        return res;
    }
};
