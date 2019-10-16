// LeetCode: 697. Degree of an Array
Degree of this array is defined as the maximum frequency of any one of its elements.
Find the smallest possible length of subarray of nums, that has the same degree as nums.
i/p: [1, 2, 2, 3, 1] & [1,2,2,3,1,4,2]
o/p: 2 & 6

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> dict;

        for (int it = 0; it < nums.size(); it++)
        {
            dict[nums[it]].push_back(it);
        }

        int maxFreq = 0;
        int len = 0;
        for (auto m : dict)
        {
            if (m.second.size() > maxFreq)
            {
                max = m.second.size();
                int s = *m.second.begin();
                int e = *(m.second.end() - 1);
                len = e - s + 1;
            }
            else if (m.second.size() == maxFreq)
            {
                int s = *m.second.begin();
                int e = *(m.second.end() - 1);
                if (e - s + 1 < len)
                {
                    len = e - s + 1;
                }
            }
        }

        return len;;
    }
};
