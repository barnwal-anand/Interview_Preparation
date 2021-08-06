/*
Leetcode: 71 Simplify Path

Given a string path, which is an absolute path (starting with a slash '/')
to a file or directory in a Unix-style file system, convert it to the simplified canonical path.

In a Unix-style file system, a period '.' refers to the current directory,
a double period '..' refers to the directory up a level, and
any multiple consecutive slashes (i.e. '//') are treated as a single slash '/'.
For this problem, any other format of periods such as '...' are treated as file/directory names.
Input: path = "/home//foo/"
Output: "/home/foo"

Input: path = "/a/./b/../../c/"
Output: "/c"
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tokens = getTokens(path);
        string res = "";
        vector<string> revRes;
        stack<string> s;

        for (int it = 0; it < tokens.size(); it++) {
            if (tokens[it] == "." || tokens[it] == "") {
                continue;
            }
            if (tokens[it] == "..") {
                if(!s.empty()) {
                    s.pop();
                }
            }
            else {
                s.push(tokens[it]);
            }
        }

        while (!s.empty()) {
            revRes.push_back(s.top());
            revRes.push_back("/");
            s.pop();
        }

        for (int it = revRes.size()-1; it >= 0; it--) {
            res += revRes[it];
        }

        return (res == "" ? "/" : res);
    }

    vector<string> getTokens(string path) {
        stringstream ss(path);
        string word;
        vector<string> tokens;

        while (getline(ss, word, '/')) {
            tokens.push_back(word);
        }

        return tokens;
    }
};
