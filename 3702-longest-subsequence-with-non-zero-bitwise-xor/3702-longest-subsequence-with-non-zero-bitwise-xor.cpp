class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // We have to handle two cases 
        // 1. when the xor of entire array is non-zero return n 
        // 2. when the xor of entire array is 0 - then further two cases
        //    when it contains atleast one non-zero return n-1 else return 0 (for all zeros case)

        int xorr = 0;
        bool nonZero = false;

        for (int i:nums){
            xorr ^= i;
            if (i!=0) nonZero = true;
        }

        if (xorr!=0) return nums.size();
        else if (nonZero==false) return 0;
        return nums.size()-1;
    }
};