class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0, r = 0, sIndex = -1, minLen = INT_MAX;
        int hash[123] = {0};

        for (int i=0;i<t.size();i++){
            hash[t[i]]++;
        }
        int count = 0;
        while(r<s.size()){
            if (hash[s[r]]>0) count++;
            hash[s[r]]--;
            while(count==t.size()){
                if (r-l+1<minLen){
                    minLen = r-l+1;
                    sIndex = l;
                }
                hash[s[l]]++;
                if (hash[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return sIndex==-1?"":s.substr(sIndex, minLen);

    }
};