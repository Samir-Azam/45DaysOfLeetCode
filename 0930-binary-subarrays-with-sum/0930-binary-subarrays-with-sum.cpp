class Solution {
public:
    int subLesserThanEqualTo(vector<int>&nums, int goal){
        if (goal<0) return 0;
        int count = 0, l = 0, r = 0;
        long long sum = 0;
        while(r<nums.size()){
            sum += nums[r];
            while(l < nums.size() && sum>goal){
                sum -= nums[l];
                l++;
            }
            if (sum<=goal) count+=(r-l+1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subLesserThanEqualTo(nums, goal)-subLesserThanEqualTo(nums, goal-1);
    }
};