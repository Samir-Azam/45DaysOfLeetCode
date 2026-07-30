class Solution {
public:
    int minimumPushes(string word) {
        // edge case for level 1
        if (word.size()<=8) return word.size();

        int n = word.size()-8;
        int ans = 8;
        int level = 2;
        while(n){
            if (n<=8){
                ans += level*n;
                break;
            }
            else{
                ans+=8*level;
                n-=8;
                level++;
            }
        }
        return ans;
    }
    
};