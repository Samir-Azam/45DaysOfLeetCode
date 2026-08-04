class Solution {
public:
    int minBitFlips(int start, int goal) {
        // It is very simple we just have to figure out how many bits are different in both of them (start and goal).
        int count = 0;
        for (int i=0;i<32;i++){
            if ((bool(start & (1<<i))) != (bool(goal & (1<<i)))) count++;
        }
        return count;
    }
};