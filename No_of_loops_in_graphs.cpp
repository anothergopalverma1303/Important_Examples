#include <bits/stdc++.h>
using namespace std;

bool isCyclic_util(vector<int> vec[], vector<bool> vis, int curr) {
	if(vis[curr]==true) {
		return true;
	}
	bool flag = false;
	vis[curr] = true;
	for(int i = 0 ; i < vec[curr].size() ; i++) {
		flag = isCyclic_util(vec, vis, vec[curr][i]);
		if(flag==true) {
			return true;
		}
	}
	return false;
}

bool isCyclic(int V, vector<int> vec[]) {
	vector<bool> vis(V, false);
	bool flag = false;
	for(int i = 0 ; i < V ; i++) {
		vis[i] = true;
		for(int j = 0 ; j < vec[i].size() ; j++) {
			flag = isCyclic_util(vec, vis, vec[i][j]);
			if(flag==true) {
				return true;
			}
		}
		vis[i] = false;
	}
	return false;
}

void addEdge(vector<int> vec[], int u, int v) {
	vec[u].push_back(v);
}
int main() {

	int V = 5;
	vector<int> vec[V];
	addEdge(vec, 1, 2);
	addEdge(vec, 2, 3);
	addEdge(vec, 3, 4);
	addEdge(vec, 4, 1);
	cout << isCyclic(V, vec) << endl;

	return 0;
}
