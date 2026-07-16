class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i<=j){
            if (s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }


    string longestPalindrome(string s) {
        int maxLen = 1;
        int start = 0;

        for (int i=0;i<s.size();i++){
            for (int j=i+1;j<s.size();j++){
                if (isPalindrome(i, j, s)) {
                    if (j-i+1>maxLen){
                        start = i;
                        maxLen = max(maxLen, j-i+1);
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};