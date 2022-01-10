class Solution {
public:
    int myAtoi(string s) {
        while(s.length() != 0 and (s[0] == ' ') )
            s.erase(0,1);
        long long int sign = 1;
        long long int Max = 2147483647;
        long long int Min = -2147483648;
        if(s[0] == '-' or s[0] == '+')
        {
            if(s[0] == '-')
                sign = -1;
            s.erase(0,1);
        }
        string str = "";
        long long int ten = 1;
        long long int num = 0;
        for(int i = 0; i < s.length(); i++)
        {
            if(!isdigit(s[i]))
                break;
            str += s[i];
        }
         while(str[0] == '0')
        {
            str.erase(0,1);
        }
        int n = str.length();
        for(int i = n - 1; i >= 0 ; i--)
        {
            num += ten * (str[i] - '0');
            ten *= 10;
            if( !(num * sign >= Min and sign * num <= Max) or ten  >= Max * 10)
            {
                if(sign == -1)
                    return Min;
                return Max;
            }
        }
        return (sign * (int)num);
    }
};