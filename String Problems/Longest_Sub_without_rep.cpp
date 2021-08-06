/*
Leetcode: 3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int windowLen = 0;
        int res = 0;
        int i = 0;
        int j = 0;
        unordered_map<char, int> umap;

        while (j < s.size()) {
            if (umap.find(s[j]) != umap.end() && umap[s[j]] >= i) {
                res = max(res, windowLen);
                i = umap[s[j]] + 1;
                windowLen = j - i + 1;
            }
            else {
                windowLen++;
            }
            umap[s[j]] = j;
            j++;
        }

        return max(res, windowLen);
    }
};
