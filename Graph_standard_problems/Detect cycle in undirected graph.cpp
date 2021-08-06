/*
Given an undirected graph with V vertices and E edges, check whether it contains any cycle or not.
Input:
5 5
0 4
1 2
1 4
2 3
3 4

Output: 1
Explanation: 1->2->3->4->1 is a cycle.

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)
*/

class Solution
{
public:
	bool isCycle(int V, vector<int>adj[])
	{
        vector<bool> visited(V, false);
	    for (int it = 0; it < V; it++) {
	        if (!visited[it] && dfsHelper(it, adj, visited, it)) {
	            return true;
	        }
	    }

	    return false;
	}

	bool dfsHelper(int V, vector<int> adj[], vector<bool> &visited, int parent) {
	    visited[V] = true;

	    // iterate for neighbours
	    for (int nbr : adj[V]) {
	        if (!visited[nbr]) {
	            bool isCyclePresent = dfsHelper(nbr, adj, visited, V);
	            if (isCyclePresent) {
	                return true;
	            }
	        }
	        else if (nbr != parent) {
	            return true;
	        }
	    }

	    return false;
	}
};
