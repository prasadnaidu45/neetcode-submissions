class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m; //element,count
        int maxi=INT_MIN;
        for(auto it:nums){
            if(m.count(it)){
                m[it]++;
            }
            else m[it]=1;
            maxi=max(maxi,m[it]);
        }
        vector<vector<int>> res(maxi+1);
        for(auto it:m){
            int idx=it.second;
            int value=it.first;
            res[idx].push_back(value);
        }
        vector<int> ans;
        int count=k;
        for(int i=maxi;i>=0;i--){
            if(count==0)
                break;
            if(res[i].size()!=0){
                for(auto it:res[i]){
                    if(count==0)
                        break;
                    ans.push_back(it);
                    count--;
                }
            }
        }
    return ans;
    }
};
