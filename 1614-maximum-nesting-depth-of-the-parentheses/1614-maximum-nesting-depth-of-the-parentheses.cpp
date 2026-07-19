class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxDepth = 0;
        for (int i=0;i<s.size();i++){
            char curr = s[i];
            if (curr=='('){
                count++;
            }else if (curr==')'){
                count--;
            }
            maxDepth = max(maxDepth, count);
        }
        return maxDepth;
    }
};