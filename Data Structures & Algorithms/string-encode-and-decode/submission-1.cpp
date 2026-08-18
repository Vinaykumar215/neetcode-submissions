class Solution {
public:

    string encode(vector<string>& strs) {
        int n=strs.size();
        string s="";
        for(int i=0;i<n;i++){
            s+=to_string(strs[i].size())+'#'+strs[i];
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i=0;
        while(i<s.length()){
            int j=i;
            while(s[j]!= '#' ){
                j++;
            }
            int length=stoi(s.substr(i,j-i));
            res.push_back(s.substr(j+1,length));
            i=j+1+length;
        }
        return res;

    }
};
