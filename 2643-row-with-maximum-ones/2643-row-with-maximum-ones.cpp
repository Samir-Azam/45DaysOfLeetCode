class Solution {
public:
    int countOnes(vector<int>&nums){
        int count = 0;
        for (int i=0;i<nums.size();i++) count+=nums[i];
        return count;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int index = -1;
        int count = -1;
        int row = mat.size();
        int col = mat[0].size();
        for (int i=0;i<row;i++){
            int ones = countOnes(mat[i]);
            if (ones>count){
                count=ones;
                index = i;
            }
        }
        return {index, count};
    }
};