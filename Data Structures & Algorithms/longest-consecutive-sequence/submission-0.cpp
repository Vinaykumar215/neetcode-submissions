class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> mp(nums.begin(),nums.end());
        int maxi=0;
        for(int num:mp){
            if(mp.find(num-1) == mp.end()){
                    int length=1;
                while(mp.find(num+length) != mp.end()){
                    length++;
                }
                maxi=max(maxi,length);
            }
        }
        return maxi;
    }
};
