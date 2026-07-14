class Solution {
public:
    long long divisionSum(vector<int>&nums, long long divisor){
        long long ans = 0;
        for (int i=0;i<nums.size();i++){
            ans+=(ceil)(nums[i]/(double)divisor);
        }
        return ans;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = INT_MAX;

        long long ans = -1;
        while(low<=high){
            long long mid = low+ (high-low)/2;
            long long sum = divisionSum(nums, mid);
            if (sum<=threshold){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};