class Solution {
public:
    bool isEqual(int freq1[26],int freq2[26]){
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        int freq[26]={0};
        int n1=s1.length();
        int n2=s2.length();
        for(int i=0;i<n1;i++){
            freq[s1[i]-'a']++;
        }
        
        for(int i=0;i<n2;i++){
            int windowstart=0,idx=i;
            int windowfreq[26]={0};
            while(windowstart<n1 && idx<n2){
                windowfreq[s2[idx]-'a']++;
                windowstart++;
                idx++;
            }

            if(isEqual(freq,windowfreq)) return true;
        }
        return false;
    }
};
