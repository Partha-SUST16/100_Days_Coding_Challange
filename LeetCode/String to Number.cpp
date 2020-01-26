#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string str)
    {
        //         int i = 0;
        //     while(str[i]==' ')
        //         i++;
        //     int sign =1,result = 0;
        //     if(str[i]=='-' || str[i]=='+')
        //         sign = (str[i++]=='+')?1:-1;

        //     while (str[i]>='0' and str[i]<='9')
        //     {
        //         if(result>INT_MAX/10 or (result==INT_MAX/10 and str[i]-'0'>7))
        //         {
        //             if(sign==1)
        //                 return INT_MAX;
        //             else
        //                 return INT_MIN;
        //         }
        //         result = result*10+(str[i++]-'0');
        //     }
        //     return result*sign;
        //stringstream s(str);
        // int a =0;
        // s >> a;
        // return a;
        if (str.empty())
            return 0;

        // remove whitespaces
        int i = 0;
        while (i < str.size() && str[i] == ' ')
            ++i;

        // after whitespace removal if the first character is anything
        // other than +,-,[0-9]
        char first_char = str[i++];
        bool negative = false;
        int result = 0;

        if (first_char != '-' && first_char != '+' &&
            ((first_char - '0') < 0 || (first_char - '0') > 9))
            return 0;

        // set sign
        negative = first_char == '-' ? true : false;
        // if first char is a digit instead of sign
        result = ((first_char - '0') >= 0 && (first_char - '0') <= 9) ? (first_char - '0') : 0;

        // construct the remaining number using chars
        // if the final number is negative then each time we add negative digits
        // this makes it possible to save it in 32-bit int otherwise overflow occurs
        while (i < str.size() && isdigit(str[i]))
        {
            int curr_digit = str[i] - '0';

            // check if the number goees beyond negative LIMIT
            if (negative && (result < (INT_MIN + curr_digit) / 10))
                return INT_MIN;
            // check if the number goees beyond positive LIMIT
            else if (!negative && (result > (INT_MAX - curr_digit) / 10))
                return INT_MAX;

            // make the current digit negative in case of negative number is final result
            if (negative)
                curr_digit *= -1;
            result = result * 10 + curr_digit;
            ++i;
        }
        return result;
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