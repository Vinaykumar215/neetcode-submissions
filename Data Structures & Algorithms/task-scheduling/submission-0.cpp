class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> freq(26);
        for(int i=0;i<tasks.size();i++){
            freq[tasks[i]-'A']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                pq.push(freq[i]);
            }
        }
        int time=0;
        while(!pq.empty()){
            vector<int> temp;
            for(int i=1;i<=n+1;i++){
                if(!pq.empty()){
                    int freqe=pq.top();
                    pq.pop();
                    freqe--;
                    temp.push_back(freqe);
                }
            }

            for(int i=0;i<temp.size();i++){
                if(temp[i]>0){
                    pq.push(temp[i]);
                }
            }

            if(pq.empty()){
                time+=temp.size();
            }else{
                time+=n+1;
            }

        }
        return time;
    }
};
