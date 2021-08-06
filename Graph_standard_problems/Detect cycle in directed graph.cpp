/*
First line of the custom input must contain two space separated integers V denoting the number of vertices and
E denoting the number of edges. Next E lines contains two space-separated integers denoting each edge.

Input:
4 4
0 1
1 2
2 3
3 3
Output: 1
Explanation: 3 -> 3 is a cycle

Expected Time Complexity: O(V + E)
Expected Auxiliary Space: O(V)
*/

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[])
	{
	   	vector<bool> visited(V, false);
	   	vector<bool> recStack(V, false);

	   	for (int v = 0; v < V; v++) {
	   	    if (!visited[v] && dfsHHelper(v, adj, visited, recStack)) {
	   	        return true;
	   	    }
	   	}

	   	return false;
	}

	bool dfsHHelper(int v, vector<int> adj[], vector<bool> &visited, vector<bool> &recStack) {
	    visited[v] = true;
	    recStack[v] = true;

	    for (int nbr : adj[v]) {
	        if (!visited[nbr]) {
	            int nbrFoundCycle = dfsHHelper(nbr, adj, visited, recStack);
	            if (nbrFoundCycle) {
	                return true;
	            }
	        }
	        else if (recStack[nbr]) {
	            return true;
	        }
	    }

	    recStack[v] = false;
	    return false;
	}
};
