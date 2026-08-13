class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;

        bool positive = true;
        if ((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) 
            positive = false;
        long long nume = llabs((long long)dividend);
        long long deno = llabs((long long)divisor);

        long long ans  = 0LL;
        while(nume>=deno){

            int power = 0;
            while((deno<<power)<=nume){
                power++;
            }
            
            power--;
            nume -= (deno<<power);
            ans += (1LL<<power);
        }

        if (positive==true){
            if (ans>INT_MAX) return INT_MAX;
            return ans;
        }else{
            if (ans>INT_MAX) return INT_MIN;
            return -ans;
        }
    }
};