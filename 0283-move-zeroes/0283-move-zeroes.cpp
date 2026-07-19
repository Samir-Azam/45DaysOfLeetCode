class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = -1;
        for (int i = 0;i<nums.size();i++){
            if (nums[i]==0){
                idx = i;
                break;
            }
        }
        if (idx==-1) return;

        
        for (int j = idx+1;j<nums.size();j++){
            if (nums[j]!=0){
                swap(nums[idx], nums[j]);
                idx++;
            }
        }
    }
};