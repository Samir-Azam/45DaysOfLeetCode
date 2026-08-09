class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int maxSum = INT_MIN;
        int l = 0;
        while(l<k){
            sum+=cardPoints[l];
            l++;
        }
        maxSum = sum;
        l--;
        int r = cardPoints.size()-1;
        while(l>=0){
            sum -= cardPoints[l--];
            sum += cardPoints[r--];
            maxSum = max(maxSum, sum);
        }
        return maxSum;

    }
};