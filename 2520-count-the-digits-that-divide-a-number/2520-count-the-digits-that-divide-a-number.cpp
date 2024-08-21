class Solution {
public:
    int countDigits(int num) {
        int temp=num;
        int cnt=0;
        while(num>0){
            int lastDigit=num%10;
            if(temp%lastDigit==0)
                cnt++;
            num=num/10;
        }
        return cnt;
    }
};