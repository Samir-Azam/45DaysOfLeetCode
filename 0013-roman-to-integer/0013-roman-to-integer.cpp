class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
        };

        int ans = 0;
        int i = 0;
        int n = s.size();
        while (i<s.size()){
            char curr = s[i];

            if (curr=='I'){
                if (i+1<n && s[i+1]=='V'){
                    ans += 4;
                    i = i+2;
                }
                else if (i+1<n && s[i+1]=='X') {
                    ans += 9;
                    i = i+2;
                }
                else {
                    ans+= 1;
                    i++;
                }
            } 
            else if (curr=='X'){
                if (i+1<n && s[i+1]=='L'){
                    ans += 40;
                    i = i+2;
                }
                else if (i+1<n && s[i+1]=='C') {
                    ans += 90;
                    i = i+2;
                }
                else {
                    ans+= 10;
                    i++;
                }
            }

            else if(curr=='C'){
                if (i+1<n && s[i+1]=='D'){
                    ans += 400;
                    i = i+2;
                }
                else if (i+1<n && s[i+1]=='M') {
                    ans += 900;
                    i = i+2;
                }
                else {
                    ans+= 100;
                    i++;
                }
            }
            else {
                ans += mp[curr];
                i++;
            }
        }
        return ans;
    }
};