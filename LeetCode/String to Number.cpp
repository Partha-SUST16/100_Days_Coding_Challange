#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        int i = 0;
        while (str[i] == ' ')
            i++;
        int sign = 1, result = 0;
        if (str[i] == '-' || str[i] == '+')
            sign = (str[i++] == '+') ? 1 : -1;

        while (str[i] >= '0' and str[i] <= '9')
        {
            if (result > INT_MAX / 10 or (result == INT_MAX / 10 and str[i] - '0' > 7))
            {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            result = result * 10 + (str[i++] - '0');
        }
        return result * sign;
    }
};

string stringToString(string input)
{
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() - 1; i++)
    {
        char currentChar = input[i];
        if (input[i] == '\\')
        {
            char nextChar = input[i + 1];
            switch (nextChar)
            {
            case '\"':
                result.push_back('\"');
                break;
            case '/':
                result.push_back('/');
                break;
            case '\\':
                result.push_back('\\');
                break;
            case 'b':
                result.push_back('\b');
                break;
            case 'f':
                result.push_back('\f');
                break;
            case 'r':
                result.push_back('\r');
                break;
            case 'n':
                result.push_back('\n');
                break;
            case 't':
                result.push_back('\t');
                break;
            default:
                break;
            }
            i++;
        }
        else
        {
            result.push_back(currentChar);
        }
    }
    return result;
}

int main()
{
    string line;
    while (getline(cin, line))
    {
        string str = stringToString(line);

        int ret = Solution().myAtoi(str);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}