class Solution {
public:
    int partition(vector<int>&nums, int k, int pages){
        int parts = 1;
        int cur = nums[0];

        for (int i=1;i<nums.size();i++){
            if (cur+nums[i]>pages){
                parts++;
                cur = nums[i];
            }else cur += nums[i];
        }
        return parts;
    }
    int splitArray(vector<int>& nums, int k) {


        int low = *max_element(nums.begin(), nums.end());

        int high = accumulate(nums.begin(), nums.end(), 0);

        while(low<=high){
            int mid = (low+high)/2;
            int parts = partition(nums, k, mid);
            if (parts<=k){
                high = mid-1;
            }else low = mid+1;
        }

        return low;
    }
};