class Solution {
public:
    double myPow(double x, int n) {
        if (n==0) return 1;
        double res = 1;
        bool positive = true;
        if (n<0) positive = false;
        long long m = llabs((long long)n);
        while(m>0){
            if (m&1LL) res *= x;
            x *= x;
            m = m>>1;
        }
        if (positive==false) return 1/res;
        return res;
    }
};