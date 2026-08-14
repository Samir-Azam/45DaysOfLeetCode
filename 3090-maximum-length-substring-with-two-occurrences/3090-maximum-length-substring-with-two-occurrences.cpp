class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = 0, n = s.size(), maxLen = 0;
        bool valid = true;
        int hash[26] = {0};
        for (int r = 0; r < n; r++){
            hash[s[r]-'a']++;
            if (hash[s[r]-'a'] > 2) valid=false;
            while(l<n && valid==false){
                hash[s[l]-'a']--;
                if (hash[s[l]-'a']==2) valid = true;
                l++;
            }
            if (valid) maxLen = max(maxLen, r-l+1);
        }
        return maxLen;
    }
};