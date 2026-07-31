class Solution {
public:
    int minimumPushes(string word) {
        
        int hash[26] = {0};

        for (char ch: word){
            hash[ch-'a']++;
        }

        sort(hash, hash+26, greater<int>());
        int count = 0;
        int ans = 0;
        for (int i=0;i<26;i++){
            if (hash[i]!=0){
                count++;
                ans+=(ceil(count/8.0)*hash[i]);
            }
        }
        return ans;
    }
};