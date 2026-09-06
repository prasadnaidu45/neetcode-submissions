class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
            int n=nums.size();
            vector<int> pre(n),post(n);
            int prod=1;
            for(int i=0;i<n;i++){
                prod*=nums[i];
                pre[i]=prod;
            }
            prod=1;
            for(int i=n-1;i>=0;i--){
                prod*=nums[i];
                post[i]=prod;
            }
            vector<int> res(n);
            res[0]=post[1];
            res[n-1]=pre[n-2];
            for(int i=1;i<n-1;i++){
                res[i]=pre[i-1]*post[i+1];
            }
            return res;
    }
};
