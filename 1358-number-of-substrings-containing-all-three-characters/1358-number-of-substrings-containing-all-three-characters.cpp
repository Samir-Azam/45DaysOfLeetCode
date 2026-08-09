class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0, r=0, n=s.size(), ans=0;
        int hash[3] = {0};

        while(r<n){
            char curr = s[r];
            hash[s[r]-'a']++;
            while(hash[0]>0 && hash[1]>0 && hash[2]>0){
                ans+=n-r;
                hash[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};