class Solution {
public:
    bool isEqual(vector<int>& freq1,vector<int>& freq2){
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> freq1(26);
        vector<int> freq2(26);
        if(s1.length() > s2.length()) return false;
        int n1=s1.length();
        int n2=s2.length();
        for(int i=0;i<n1;i++){
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }

        if(isEqual(freq1,freq2)) return true;
        for(int i=n1;i<n2;i++){
            freq2[s2[i]-'a']++;
            freq2[s2[i-n1]-'a']--;
            if(isEqual(freq1,freq2)) return true;
        }
        return false;
    }
};
