class Solution {
public:


    int beautySum(string s) {
        
        int n = s.size();
        int summation = 0;

        for (int i=0;i<n;i++){
            vector<int>mp(26,0);

            for (int j=i;j<n;j++){
                
                mp[s[j]-'a']++;
                int minf = mp[s[j]-'a'];
                int maxf = mp[s[j]-'a'];
                for (int k=0;k<26;k++){
                    maxf = max(maxf, mp[k]);
                    if (mp[k]!=0) minf = min(minf, mp[k]);
                }
                summation+=maxf-minf;
            }
        }
        return summation;
    }
};