class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int>mp;
        int l=0, r=0, n=s.size();
        int maxLen = 0;
        while(r<n){
            char curr = s[r];
            if (mp.find(curr)!=mp.end() && l<=mp[curr]){
                l = mp[curr]+1;
            }
            maxLen = max(maxLen, r-l+1);
            mp[curr] = r;
            r++;
        }
        return maxLen;
    }
};