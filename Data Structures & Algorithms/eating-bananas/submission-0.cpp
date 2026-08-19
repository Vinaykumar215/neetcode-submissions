class Solution {
public:
    bool CanHeEat(vector<int>& piles,int h,int mid){
        int eat=0;
        for(int i=0;i<piles.size();i++){
            eat+=(ceil)((double)piles[i]/mid);
        }
        if(eat<=h){
            return true;
        }else{
            return false;
        }
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s=1;
        int maxi=INT_MIN;
        int n=piles.size();
        for(int i=0;i<n;i++){
            maxi=max(maxi,piles[i]);
        }
        int e=maxi;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(CanHeEat(piles,h,mid)){
                ans=mid;
                e=mid-1;
            }else{
                s=mid+1;
            }

        }
        return ans;
    }
};
