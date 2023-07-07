// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Graph {
private:
	int V;
	vector<int> *adj;

public:
	Graph(int V) {
		this->V = V;
		adj = new vector<int>[V];
	}
	
	void addEdge(int x, int y) {
		adj[x].push_back(y);
	}
	
	void printGraph() {
		for(int it = 0; it < V; it++){
			cout << it << "-->";
			
			for(auto nbr: adj[it]){
				cout << nbr << ", ";
			}
			cout << endl;
		}
	}
	
	vector<int> bfsOfGraph() {
       vector<int> result;
       vector<bool> visited(V, false);
       queue<int> q;
       
       q.push(0);
       visited[0] = true;
       
       while(!q.empty()) {
           int temp = q.front();
           result.push_back(temp);
           q.pop();
           
           
           for(auto nbr: adj[temp]) {
               if(!visited[nbr]) {
                   q.push(nbr);
                   visited[nbr]=true;
               }
           }
       }
       
       return result;
    }
};

int main() {
	// your code goes here
	Graph *graph = new Graph(5);
	graph->addEdge(0,1);
	graph->addEdge(0,2);
	graph->addEdge(0,3);
	graph->addEdge(2,4);
	
	graph->printGraph();
	vector<int> bfs = graph->bfsOfGraph();
	
	for(auto node: bfs) {
		cout << node << " ";
	}
	return 0;
}
