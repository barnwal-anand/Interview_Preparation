/*
Find the number of unique k-diff pairs
i/p: [3, 1, 4, 1, 5], k = 2
o/p: 2
*/
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0)
            return 0;

        int count = 0;
        unordered_map<int, int> freq;

        for (int num : nums)
            freq[num]++;

        unordered_map<int, int>::iterator itr;

        for (itr = freq.begin(); itr != freq.end(); itr++)
        {
            cout << itr->first << " " << itr->second<< endl;
            if (k == 0 && itr->second > 1)
                count++;

            else if (k && freq.count(itr->first + k))  // here need to use freq.count instead of freq[]
                count++;

        }

        return count;
    }
};
