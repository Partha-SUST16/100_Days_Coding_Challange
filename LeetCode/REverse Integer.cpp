#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long n = 0;
        while (x != 0)
        {
            n = n * 10 + x % 10;
            x /= 10;
        }
        if (n < INT_MIN || n > INT_MAX)
            return 0;
        else
            return (int)n;
    }
};