class Solution
{
public:
    int nextGreaterElement(int n)
    {
        string str = to_string(n);
        int len = str.length();
        if (len == 1)
            return -1;
        int k = len - 2;
        while (k >= 0 && str[k] >= str[k + 1])
            k--;
        if (k == -1)
            return -1;
        int justSmall = str[k];
        for (int j = len - 1; j >= 0; j--)
        {
            if (str[j] > justSmall)
            {
                swap(str[j], str[k]);
                break;
            }
        }
        reverse(str.begin() + k + 1, str.end());
        long ans = stol(str);
        if (ans > INT_MAX)
            return -1;
        return ans;
    }
};