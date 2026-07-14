class Solution {
public:
    string largestOddNumber(string num) {
        int index = -1;
        for (int i=num.size()-1;i>=0;i--){
            if ((num[i]-'0')&1){
                index = i;
                break;
            }
        }

        string ans = "";
        if (index==-1) return ans;
        int i = 0;
        // while(i<=index && (num[i]-'0')==0) i++;

        ans  = num.substr(i, index-i+1);
        return ans; 

    }
};