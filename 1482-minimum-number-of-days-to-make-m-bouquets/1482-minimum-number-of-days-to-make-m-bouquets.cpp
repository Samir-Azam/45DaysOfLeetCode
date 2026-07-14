class Solution {
public:
    int bouquetsCount(vector<int>&bloomDay, int day, int k){
        int count = 0;
        int adj = 0;
        for (int i=0;i<bloomDay.size();i++){
            if (bloomDay[i]<=day) adj++;
            else adj = 0;

            if (adj==k){
                count++;
                adj=0;
            }
        }
        return count;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        

        int low = 1;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;

            int count = bouquetsCount(bloomDay, mid, k);
            if (count>=m){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};