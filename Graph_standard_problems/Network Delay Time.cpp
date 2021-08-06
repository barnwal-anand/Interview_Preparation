/*
Leetcode: 743 Network Delay Time
You are given a network of n nodes, labeled from 1 to n.
You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi),
where ui is the source node, vi is the target node, and
wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k.
Return the time it takes for all the n nodes to receive the signal.
If it is impossible for all the n nodes to receive the signal, return -1.

Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
*/

// We can use Dijkshtra's algo to find min distance from k to all nodes and then find max of all distances
class Graph {
private:
    int v;

public:
    list<pair<int, int>> *adjList;

    Graph(int n) {
        v = n;
        adjList = new list<pair<int, int>>[n];
    }
    void addEdge(int src, int dest, int wt) {
        adjList[src].push_back({wt, dest});
    }

    void printList() {
        for (int it = 1; it <= v; it++) {
            cout << it << endl;
            for (auto node : adjList[it]) {
                cout << node.second << " " << node.first << endl;
            }

        }
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        Graph graph(n+1);
        set<pair<int, int>> s;
        vector<int> dist(n, INT_MAX);

        for(auto edge : times) {
            graph.addEdge(edge[0], edge[1], edge[2]);
        }

        s.insert({0, k});
        dist[k-1] = 0;

        while(!s.empty()) {
            auto it = s.begin();
            int node = it->second;
            int nodeDist = it->first;
            s.erase(it);

            for(auto nbr : graph.adjList[node]) {
                int newDist = nodeDist + nbr.first;

                if(newDist < dist[nbr.second - 1]) {
                    s.insert({newDist, nbr.second});
                    dist[nbr.second - 1] = newDist;
                }
            }
        }

        int res = -1;
        for(int it = 0; it < n; it++) {
            res = max(res, dist[it]);
        }

        return res != INT_MAX ? res : -1;
    }
};
