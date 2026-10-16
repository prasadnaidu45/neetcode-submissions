class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,n=s.size();
        int res=0;
        unordered_set<char> m;
        while(i<n){
            char ch=s[i];
            if(m.find(ch)!=m.end()){
                while(s[j]!=ch){
                    m.erase(s[j]);
                    j++;
                }
                j++;
            }
            m.insert(ch);
            int curr=m.size();
            res=max(res,curr);
            i++;
        }
        return res;
    }
};
