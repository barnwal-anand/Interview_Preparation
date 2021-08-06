/*
There are given N ropes of different lengths, we need to connect these ropes into one rope.
The cost to connect two ropes is equal to sum of their lengths.
The task is to connect the ropes with minimum cost.

Input:
n = 4
arr[] = {4, 3, 2, 6}
Output: 29
*/

class Solution
{
    public:
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        long long cost = 0;

        for (long long it = 0; it < n; it++) {
            pq.push(arr[it]);
        }

        while(pq.size() > 1) {
            long long num1 = pq.top();
            pq.pop();
            long long num2 = pq.top();
            pq.pop();

            cost += num1 + num2;
            pq.push(num1 + num2);
        }

        return cost;
    }
};
