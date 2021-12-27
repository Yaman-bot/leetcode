class Solution {
public:
    int reverse(int x) {
        if (x==0)return 0;
        int sign = x/abs(x);
        int y = abs(x);
        int b = 0;
        while (y>0){
            if (b>214748364)return 0;
            b *= 10;
            if (2147483647-(y%10)<b)return 0;
            b += (y%10);
            y/=10;
        }
        return b*sign;
    }
};