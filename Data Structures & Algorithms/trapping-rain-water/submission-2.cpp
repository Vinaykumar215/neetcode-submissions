class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int lmax=0,rmax=0;
        
        int area=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(height[l]<lmax){
                    area+=lmax-height[l];
                }else{
                    lmax=height[l];
                }
                l++;
            }else{
                if(height[r]<rmax){
                    area+=rmax-height[r];
                }else{
                    rmax=height[r];
                }
                r--;
            }
        }
        return area;
    }
};
