class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0, r = 0, n = nums.size(), maxLen = 0, count = 0;
        while(r<n){
            if (nums[r]==0) count++;
            if (l<n && count>k){
                if (nums[l]==0) count--;
                l++;
            }
            
            if (count<=k) maxLen = max(maxLen, r-l+1);
            r++;
        }
        return maxLen;
    }
};