/*
Leetcode: 452 Minimum Number of Arrows to Burst Balloons
There are some spherical balloons spread in two-dimensional space.
For each balloon, provided input is the start and end coordinates of the horizontal diameter.
Since it's horizontal, y-coordinates don't matter, and hence the x-coordinates of start and end of the diameter suffice.
The start is always smaller than the end.

An arrow can be shot up exactly vertically from different points along the x-axis.
A balloon with xstart and xend bursts by an arrow shot at x if xstart ≤ x ≤ xend.
There is no limit to the number of arrows that can be shot. An arrow once shot keeps traveling up infinitely.

Given an array points where points[i] = [xstart, xend]
Return the minimum number of arrows that must be shot to burst all balloons.

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: One way is to shoot one arrow for example at x = 6 (bursting the balloons [2,8] and [1,6]) and
another arrow at x = 11 (bursting the other two balloons).
*/
bool myComparator(const vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), myComparator);
        int count = 1;
        int res = 0;
        int etime = points[0][1];

        for (int it = 1; it < points.size(); it++) {
            if (points[it][0] <= etime) {
                etime = min(etime, points[it][1]);
            }
            else {
                count++;
                etime = points[it][1];
            }
         }

        return count;
    }
};
