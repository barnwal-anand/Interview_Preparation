/*
LeetCode: 973 K Closest Points to Origin

Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k,
return the k closest points to the origin (0, 0).

You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

Input: points = [[3,3],[5,-1],[-2,4]], k = 2
Output: [[3,3],[-2,4]]
*/

// Time Complexity - K + (n-K)logK [Using max heap of k size]
class Comparator {
    public:
    int operator() (const vector<int> &a, const vector<int> &b) {
        int d1 = a[0] * a[0] + a[1] * a[1];
        int d2 = b[0] * b[0] + b[1] * b[1];

        return d1 < d2;
    }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;

        for (int it = 0; it < points.size(); it++) {
            if (it < K) {
                pq.push(points[it]);
            }
            else {
                if (dist(points[it]) <= dist(pq.top())) {
                    pq.pop();
                    pq.push(points[it]);
                }
            }
        }

        while (!pq.empty()) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }

    int dist(vector<int> point) {
        return point[0] * point[0] + point[1] * point[1];
    }
};

// Using min heap - Time Complexity: n + KlogN
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        priority_queue< vector<int>, vector<vector<int>>, Comparator> pq;
        vector<vector<int>> res;

        for (int it = 0; it < points.size(); it++) {
            pq.push(points[it]);
        }
        while (K) {
            res.push_back(pq.top());
            pq.pop();
            K--;
        }

        return res;
    }
};
