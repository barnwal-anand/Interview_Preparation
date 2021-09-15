/*
Leetcode: 239. Sliding Window Maximum
You are given an array of integers nums,
there is a sliding window of size k which is moving from the very left of the array to the very right.
You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> dq(k);

        for (int it = 0; it < k; it++) {
            //pop_back smaller element from dq. To keep max only
            while (!dq.empty() && nums[it] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(it);
        }

        //Now iterate over each window and get max as dq is maintaing max at front
        for (int it = k; it < nums.size(); it++) {
            res.push_back(nums[dq.front()]);

            // contract the window if dq has any element outside it-k range
            while (!dq.empty() && dq.front() <= it-k) {
                dq.pop_front();
            }

            while (!dq.empty() && nums[it] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(it);
        }

        // take care of last element in the dq
        if (!dq.empty()) {
            res.push_back(nums[dq.front()]);
        }

        return res;
    }
};
