class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int capacity;
    KthLargest(int k, vector<int>& nums) {
        capacity=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size() > k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > capacity){
            pq.pop();
        }
        return pq.top();
    }
};
