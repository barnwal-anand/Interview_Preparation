/*
Leetcode: 22. Generate Parentheses
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string output;
        generateAll(n, 0, res, 0, output);
        return res;
    }

    void generateAll(int n, int it, vector<string> &res, int count, string output) {
        if (count < 0 || count > n)
            return;

        if (it == 2 * n) {
            if (count == 0)
                res.push_back(output);
            return;
        }

        generateAll(n, it+1, res, count+1, output+"(");
        generateAll(n, it+1, res, count-1, output+")");

    }
};
