class Solution {
public:
    int numberOfSubstrings(string s) {
        int hashArray[] = {-1, -1, -1};

        int count = 0;
        for (int i=0;i<s.size();i++){
            hashArray[s[i]-'a'] = i;
            if (hashArray[0]!=-1 && hashArray[1]!=-1 && hashArray[2]!=-1){
                int min = *min_element(hashArray, hashArray+3);
                count += (1+min);
            }
        }
        return count;
    }
};