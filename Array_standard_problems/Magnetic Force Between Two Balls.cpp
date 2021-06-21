/*
Leetcode: 1552. Magnetic Force Between Two Balls
*/

class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());

        int low = 0;
        int size = position.size();
        int high = position[size-1] - position[0];
        int res = 0;

        while (low <= high) {
            int mid = low + (high - low)/2;

            if (canPlace(position, mid, m)) {
                res = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return res;
    }

    bool canPlace(vector<int>& arr, int gap, int m) {
        int start = arr[0];
        m -= 1;
        int lastPos = 0;

        for (int it = 1; it < arr.size(); it++) {
            if (arr[it] - arr[lastPos] >= gap) {
                m--;
                lastPos = it;

                if (m == 0)
                    return true;
            }
        }

        return false;
    }
};
