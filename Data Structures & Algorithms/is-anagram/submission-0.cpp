class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m;
        for(auto it:s){
            if(!m.count(it))
                m[it]=1;
            else
                m[it]++;
        }
        for(auto it:t){
            if(m[it]==0 || !m.count(it))
                return false;
            else{
                m[it]--;
            }
        }
        for(auto it:m){
            if(it.second>0)
                return false;
        }
        return true;
    }
};
