class Solution {
public:
    string minWindow(string s, string t) {
        int arr[256] = {0};
        for (int i=0;i<t.size();i++){
            arr[t[i]]++;
        }
        int l=0, r=0, sIndex=-1, count=0, minLength=INT_MAX;
        while(r<s.size()){
            if (arr[s[r]]>0) count++;
            arr[s[r]]--;
    
            while(count==t.size()){
                if (r-l+1<minLength){
                    minLength = min(minLength, r-l+1);
                    sIndex = l;
                }
                if (arr[s[l]]==0) count--;
                arr[s[l]]++;
                l++;
            }
            r++;
        }
        
        return sIndex==-1?"":s.substr(sIndex, minLength);
    }
};