/*
Leetcode: 179 Largest Number
Given a list of non-negative integers nums, arrange them such that they form the largest number.
Note: The result may be very large, so you need to return a string instead of an integer.

Input: nums = [10,2]
Output: "210"

Input: nums = [3,30,34,5,9]
Output: "9534330"
*/
bool myComparator(const int &a, const int &b) {
    string num1 = to_string(a) + to_string(b);
    string num2 = to_string(b) + to_string(a);

    return num1 > num2;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string res = "";

        sort(nums.begin(), nums.end(), myComparator);

        if (nums[0] == 0)
            return "0";

        for (auto num : nums) {
            res += to_string(num);
        }

        return res;
    }
};
