class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       unordered_map<int, int>types;

       int l = 0, r = 0, fruitsCount = 0, n = fruits.size();

       while(r<n){
        types[fruits[r]]++;
        if (l<n && types.size()>2){
            types[fruits[l]]--;
            if (types[fruits[l]]==0) types.erase(fruits[l]);
            l++;
        }
        if (types.size()<=2) fruitsCount = max(fruitsCount, r-l+1);
        r++;
       } 
       return fruitsCount;
    }
};