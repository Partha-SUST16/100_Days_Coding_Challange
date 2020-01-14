#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> sums;
        map<int, int> mp;
        for (int i = 0; i < nums.size(); i++)
        {
            int remaingValue = target - nums[i];
            if (mp.find(remaingValue) != mp.end())
            {
                sums.push_back(mp[remaingValue]), sums.push_back(i);
                return sums;
            }

            mp[nums[i]] = i;
        }
        return sums;
    }
};