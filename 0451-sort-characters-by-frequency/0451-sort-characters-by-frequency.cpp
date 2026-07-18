class Solution {
public:

    string frequencySort(string s) {
        // integer to store frequency and second int to store current character
        pair<int, int> freq[256] ;

        for (int i=0;i<256;i++){
            freq[i] = {0, i};
        }

        for (int i=0;i<s.size();i++){
            freq[s[i]].first++;
        }

        sort(freq, freq+256, greater<pair<int,int>>());
        int i = 0;
        string ans = "";    
        while(freq[i].first!=0){
            while(freq[i].first--){
                ans+=char(freq[i].second);
            }
            i++;
        }
        return ans;

    }
};