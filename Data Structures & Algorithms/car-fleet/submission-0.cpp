class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> merged;
        int n=position.size();
        for(int i=0;i<n;i++){
            merged.push_back({position[i],speed[i]});
        }
        vector<double> st;
        sort(merged.rbegin(),merged.rend());
        for(auto& p:merged){
            st.push_back((double)(target-p.first)/(p.second));
            if(st.size() >=2 && st.back()<=st[st.size()-2]){
                st.pop_back();
            }
        }
        return st.size();
    }
};
