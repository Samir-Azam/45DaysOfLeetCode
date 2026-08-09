class Solution {
public:
    int lesserOrEqualCount(vector<int>&nums, int k){
        if (k<0) return 0;
        int count = 0, l = 0, r = 0, n = nums.size(), total = 0;

        while(r<n){
            count += (nums[r]&1);
            while(count>k){
                count-=nums[l]&1;
                l++;
            }
            if (count<=k) total+=(r-l+1);
            r++;
        }
        return total;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return lesserOrEqualCount(nums, k) - lesserOrEqualCount(nums, k-1);
    }
};