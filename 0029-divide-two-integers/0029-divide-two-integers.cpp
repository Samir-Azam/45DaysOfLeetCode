class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        bool sign = true;
        if ((dividend>=0 && divisor<0) || (dividend<=0 && divisor>0)) sign = false;

        long nume = abs(long(dividend));
        long deno = abs(long(divisor));

        long ans = 0;
        while (nume >= deno){
            long power = 0;
            while(deno<<(power+1)<=nume){
                power++;
            }
            nume -= deno<<power;
            ans += 1<<power; 
        }
        if (sign==false && ans==(1<<31)) return INT_MIN;
        if (sign==true && ans==(1<<31)) return INT_MAX;

        if (sign==false) return ans*(-1);
        return ans;
    }
};