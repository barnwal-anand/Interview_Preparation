/*
LeetCode: 767 - Reorganize String

Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.

Input: s = "aab"
Output: "aba"

Input: s = "aaab"
Output: ""
*/

class MyComparator {
public:
    bool operator() (const pair<char, int> &a, const pair<char, int> &b) {
        return a.second < b.second;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> map;
        priority_queue<pair<char, int>, vector<pair<char, int>>, MyComparator> pq;
        string res = "";
        pair<int, int> prev('#', -1);
        
        for(int it = 0; it < s.size(); it++) {
            map[s[it]]++;
        }
        
        for(auto ch_freq_pair : map) {
            pq.push(ch_freq_pair);
        }
        
        while(!pq.empty()) {
            pair<char, int> cur = pq.top();
            pq.pop();
            res += cur.first;
            
            if (prev.second > 0) {
                pq.push(prev);
            }
            
            cur.second--;
            prev = cur;
        }
        
        if (res.size() == s.size()) {
            return res;
        }
        
        return "";
    }
};
