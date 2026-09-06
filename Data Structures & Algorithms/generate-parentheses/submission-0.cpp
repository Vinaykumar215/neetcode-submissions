class Solution {
public:
    void solve(int n,vector<string>& ans,int open,int close,string& s){
        if(open == close && open==n){
            ans.push_back(s);
            return;
        }
        if(open < n){
            s+='(';
            solve(n,ans,open+1,close,s);
            s.pop_back();
        }
        if(close<open){
            s+=')';
            solve(n,ans,open,close+1,s);
            s.pop_back();
        }

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;
        solve(n,ans,0,0,s);
        return ans;
    }
};
