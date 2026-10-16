class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        for(int i=0;i<k;i++)
            sum+=cardPoints[i];
        int res=sum;
        int j=k;
        for(int i=n-1;i>=n-k;i--){
            sum=sum-cardPoints[j-1]+cardPoints[i];
            res=max(sum,res);
            j--;
        }
        return res;
    }
};