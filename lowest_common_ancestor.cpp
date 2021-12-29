#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 1;
std::vector<int> g[N];
int par[N];

void dfs(int v, int p = -1){
	par[v] = p;
	for(int child : g[v]){
		if(child == p){
			continue;
		}
		dfs(child, v);
	}
}

vector<int> get_path(int v){
	vector<int> path;
	while(v != -1){
		path.push_back(v);
		v = par[v];
	}
	reverse(path.begin(), path.end());
	return path;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; ++i){
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(1);
	int u, v;
	cin >> u >> v;
	std::vector<int> path_u = get_path(u);
	std::vector<int> path_v = get_path(v);
	int lca = -1;
	for(int i = 0; i < (int)min(path_v.size(), path_u.size()); ++i){
		if(path_u[i] == path_v[i]){
			lca = path_u[i];
		}else{
			break;
		}
	} 
	cout << lca << '\n';
	return 0;
}