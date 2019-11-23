// LeetCode: 849. Maximize Distance to Closest Person
Input: [1,0,0,0,1,0,1]
Output: 2
Explanation:
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int size = seats.size();
        vector<int> left(size, size);
        vector<int> right(size, size);

        for (int it = 0; it < size; it++)
        {
            if (seats[it] == 1)
                left[it] = 0;
            else if (it > 0)
                left[it] = left[it - 1] + 1;
        }

        for (int it = size - 1; it >= 0; it--)
        {
            if (seats[it] == 1)
                right[it] = 0;
            else if (it < size - 1)
                right[it] = right[it + 1] + 1;
        }

        int res = -1;
        for (int it = 0; it < size; it++)
        {
            if (seats[it] == 0)
            {
                res = max(res, min(left[it], right[it]));
            }
        }

        return res;
    }
};
