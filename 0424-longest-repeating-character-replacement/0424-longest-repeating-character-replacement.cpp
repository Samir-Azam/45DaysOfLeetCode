class Solution {
public:
    int maxFrequency(vector<int>& freq){
        int maxi = 0;
        for (int i: freq){
            maxi = max(maxi, i);
        }
        return maxi;
    }
    int characterReplacement(string s, int k) {
        vector<int>freq(26, 0);
        int l = 0, r = 0, ans = 0, n = s.size();
        while(r<n){
            char curr = s[r];
            freq[curr-'A']++;
            int maxFreq = maxFrequency(freq);
            int flips = (r-l+1) - (maxFreq);

            if (flips>k){
                freq[s[l]-'A']--;
                l++;
            }

            if (flips<=k) ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};