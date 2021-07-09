/*
HackerRank: Count Triplets

You are given an array and you need to find number of tripets of indices
such that the elements at those indices are in geometric progression for a given common ratio  and .

The first line contains two space-separated integers n and r, the size of arr and the common ratio.
The next line contains n space-seperated integers
6 3
1 3 9 9 27 81
o/p: 6
*/

long countTriplets(vector<long> arr, long r) {
    unordered_map<long, long> rightHashMap;
    unordered_map<long, long> leftHashMap;
    long res = 0;

    for (auto num : arr) {
        rightHashMap[num]++;
    }

    for (long it = 0; it < arr.size(); it++) {
        rightHashMap[arr[it]]--;

        if (arr[it] % r == 0) {
            long a = arr[it] / r;
            long ar2 = arr[it] * r;

            res += leftHashMap[a] * rightHashMap[ar2];
        }

        leftHashMap[arr[it]]++;
    }

    return res;
}
