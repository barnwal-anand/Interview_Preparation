/*
LeetCode: 1010. Pairs of Songs With Total Durations Divisible by 60

Input: [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
*/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int count = 0;

        //logic: x + y = 60
        // x = 60 -y

        unordered_map<int, int> freq;
        for (int it = 0; it < time.size(); it++)
        {
            int mod = time[it] % 60;
            count += freq[(60 - mod) % 60]; // % 60 is used to overcome (0 % 60) and (60 % 60) case
            freq[mod]++;
        }

        return count;
    }
};
