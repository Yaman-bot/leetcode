class Solution {
public:
    int reverse(int x) {
        int ans=0;
        if(x==0)
            return ans;
        int sign=x/abs(x);
        x=abs(x);
        while(x>0){
            int lastDigit=x%10;
            
            if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)) 
                return 0; // Return 0 if reversing x would cause overflow/underflow
            
            ans=(ans*10) + lastDigit;
            x=x/10;
        }
        return ans*sign;
    }
};