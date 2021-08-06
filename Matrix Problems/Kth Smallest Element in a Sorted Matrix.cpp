/*
Leetcode: Kth Smallest Element in a Sorted Matrix

Given an n x n matrix where each of the rows and columns are sorted in ascending order,
return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13
*/

class myComparator {
    public:
    int operator() (const vector<int> &a, const vector<int> &b) {
        return a[0] > b[0];
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, myComparator> pq;

        int R = matrix.size();
        int C = matrix[0].size();
        int count = 0;
        int res;

        for(int c = 0; c < C; c++) {
            pq.push({matrix[0][c], 0, c});
        }

        while (count < k) {
            vector<int> cur = pq.top();
            pq.pop();
            res = cur[0];

            int nextR = cur[1] + 1;
            int curC = cur[2];

            if (nextR < R) {
                pq.push({matrix[nextR][curC], nextR, curC});
            }

            count++;
        }

        return res;
    }
};
