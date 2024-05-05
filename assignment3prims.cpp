#include <bits/stdc++.h>
using namespace std;
// print graph of result tree 

class Solution
{
public:
	int spanningTree(int V, vector<vector<vector<int>>> &adj)
	{
		priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			if (vis[node] == 1) continue;
			vis[node] = 1;
			sum += wt;
			for (auto it : adj[node]) {
				int adjNode = it[0];
				int edW = it[1];
				if (!vis[adjNode]) {
					pq.push({edW, adjNode});
				}
			}
		}
		return sum;
	}
};


int main() {

cout << "ENter ";
	int V;cin >> V;
	vector<vector<int>> edges;
	int e;cin >> e;
	for(int i=0;i<e;i++)
	{
		int w;cin>>w;
		int a;cin >> a;
		int b; cin >> b;
		edges.push_back({w,a,b});
	}
	vector<vector<vector<int>>> adj(V);
	cout << "don";
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	Solution obj;
	int sum = obj.spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}
