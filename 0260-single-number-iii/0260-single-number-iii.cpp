class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>ans;

        long long res = 0;
        for (int i=0;i<nums.size();i++){
            res^=nums[i];
        }

        long long val = (res&(res-1))^res;

        int b1 = 0, b2 = 0;
        for (int i=0;i<nums.size();i++){
            if (nums[i]&val) b1 ^= nums[i];
            else b2 ^= nums[i];
        }
        ans.push_back(b1);
        ans.push_back(b2);
        return ans;
    }
};