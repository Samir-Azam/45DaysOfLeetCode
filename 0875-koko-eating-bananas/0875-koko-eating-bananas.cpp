class Solution {
public:
    long long helper(vector<int>&piles, int speed){
        
        long long time = 0;
        for (int i=0;i<piles.size();i++){
            time += (piles[i]/speed);
            if (piles[i]%speed) time++;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;

            long long hours = helper(piles, mid);
            if (hours<=h){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};