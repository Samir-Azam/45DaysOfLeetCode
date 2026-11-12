class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int count = 0;
        int ans = 1;
        int previous = -1; 
        // strictly greater
        for (int i =0; i<nums.size(); i++){
            if (nums[i]>previous){
                count++;
                ans = max(ans, count);
            }else{
                count = 1;
            }
            previous=nums[i];
        }

        // strictly decreasing
        previous = 51;
        count = 0;
        for (int i =0; i<nums.size(); i++){
            if (nums[i]<previous){
                count++;
                ans = max(ans, count);
            }else{
                count = 1;
            }
            previous=nums[i];
        }
        
        return ans;
    }
};