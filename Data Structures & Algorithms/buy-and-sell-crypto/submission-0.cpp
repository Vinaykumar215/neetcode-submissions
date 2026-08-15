class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxi=0;
        for(int i=0;i<prices.size();i++){
            int diff=prices[i]-mini;
            maxi=max(maxi,diff);
            mini=min(mini,prices[i]);
        }
        return maxi;
    }
};
