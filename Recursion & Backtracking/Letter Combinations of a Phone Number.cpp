/*
Leetcode: 17 Letter Combinations of a Phone Number
Given a string containing digits from 2-9 inclusive, return all possible letter combinations
that the number could represent. Return the answer in any order.

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0)
            return {};
            
        string keypad[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",
                          "wxyz"};
        vector<string> res;
        string output;

        letterCombinationsUtil(digits, 0, keypad, output, res);

        return res;
    }

    void letterCombinationsUtil(const string &digits, int it, const string keypad[],
                               string output, vector<string> &res) {

        if (it == digits.length()) {
            res.push_back(output);
            return;
        }

        int curDigit = digits[it] - '0';

        if (curDigit < 2) {
            letterCombinationsUtil(digits, it+1, keypad, output, res);
        }

        for (int i = 0; i < keypad[curDigit].size(); i++) {
            letterCombinationsUtil(digits, it+1, keypad, output+keypad[curDigit][i], res);
        }
    }
};
