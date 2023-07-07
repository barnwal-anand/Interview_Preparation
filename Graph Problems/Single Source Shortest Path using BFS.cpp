#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
	int V;
	vector<pair<int, int>> *adj;

public:
	Graph(int V) {
		this->V = V;
		adj = new vector<pair<int, int>>[V];
	}
	
	void addEdge(int x, int y) {
		adj[x].push_back({y, 0});
		adj[y].push_back({x, 0});
	}
	
	void printGraph() {
		for(int it = 0; it < V; it++){
			cout << it << "-->";
			
			for(auto nbr: adj[it]){
				cout << nbr.first << ", ";
			}
			cout << endl;
		}
	}
	
	vector<pair<int, int>> bfsOfGraph(int src, int dest = -1) {
       vector<pair<int, int>> result;
       vector<bool> visited(V, false);
       vector<int> parent(V);
       queue<pair<int, int>> q;
       
       q.push({src, 0});
       visited[src] = true;
       parent[src] = src;
       
       while(!q.empty()) {
           pair<int, int> temp = q.front();
           result.push_back(temp);
           q.pop();
           int dist = temp.second;
           for(auto nbr: adj[temp.first]) {
               if(!visited[nbr.first]) {
            	   parent[nbr.first] = temp.first;
                   q.push({nbr.first, dist+1});
                   visited[nbr.first] = true;
               }
           }
       }
       
       if(dest != -1) {
    		while(dest != src) {
    			cout << dest << "--> ";
    			int temp = parent[dest];
    			dest = temp;
    		}
       }
       
       return result;
    }
};

int main() {
	// your code goes here
	Graph *graph = new Graph(7);
	graph->addEdge(1,2);
	graph->addEdge(1,0);
	graph->addEdge(2,3);
	graph->addEdge(0,4);
	graph->addEdge(3,5);
	graph->addEdge(3,4);
	graph->addEdge(4,5);
	graph->addEdge(5,6);
	
	graph->printGraph();
	vector<pair<int,int>> bfs = graph->bfsOfGraph(1, 6);
	
	for(auto node: bfs) {
		cout << node.first << " (" << node.second << ")" << endl;
	}
	return 0;
}