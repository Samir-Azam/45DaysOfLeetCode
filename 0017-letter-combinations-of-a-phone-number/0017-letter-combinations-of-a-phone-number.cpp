class Solution {
public:
    void helper(int idx, string s, vector<string>&ans, string& digits, map<int, string> &mp){

        if (s.size()==digits.size()){
            ans.push_back(s);
            return;
        }
        
        int curr = int(digits[idx]-'0');
        int n = mp[curr].size();
        string alphabet = mp[curr];
        for (int i=0;i<n;i++){
            helper(idx+1, s+alphabet[i], ans, digits, mp);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<int, string>mp = {{2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};
        vector<string>ans;

        // calling helper function
        helper(0, "", ans, digits, mp);
        return ans;
    }
};