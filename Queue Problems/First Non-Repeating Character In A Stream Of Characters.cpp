/*
i/p = "abadbc"
o/p = "aabbdd"

i/p = "abcabc"
o/p = "aaabc#"

Given a string A denoting a stream of lowercase alphabets. You have to make new string B.
B is formed such that we have to find first non-repeating character each time a character is inserted to the stream
and append it at the end to B. If no non-repeating character is found then append '#' at the end of B.
*/

string Solution::solve(string A) {
    queue<char> q;
    unordered_map<char, int> freq_table;
    string res = "";

    for (char ch : A) {
        freq_table[ch]++;
        if (freq_table[ch] == 1) {
            q.push(ch);
        }
        else {
            while (!q.empty() && freq_table[q.front()] > 1) {
                q.pop();
            }
        }

        if (!q.empty())
            res += q.front();
        else
            res += '#';
    }

    return res;
}
