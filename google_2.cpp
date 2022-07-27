
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

vector<vector<int>> adj;
vector<int> values;

bool dfs(int u, int des, vector<bool> &visited, int &init){
	visited[u] = true;
	// if(u == des) return true;

	for(int v : adj[u]){
		// debug(u, v, des);
		if(v == des) return true;
		if(!visited[v] && values[v] < init){
			if(dfs(v, des, visited, init)) return true;
		}
	}

	return false;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int n; cin >> n;
	adj.clear();
	adj.resize(n+1);
	for(int i=0; i<n-1; i++){
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	// debug(adj);
	values.clear();
	values.resize(n+1);

	map<int, vector<int>> m;
	for(int i=1; i<=n; ++i) {
		cin >> values[i];
		m[values[i]].push_back(i);
	}

	vector<bool>visited(n+1, false);	
	int ans = 0;		
	for(pair<int, vector<int>> idx : m){
		if(idx.second.size() <= 1) continue;
		vector<int> nodes = idx.second;
		// debug(nodes);
		int cnt = 0;
		for(int i=0; i<nodes.size(); ++i){
			for(int j=i+1; j<nodes.size(); ++j){
				visited.clear();
				visited.resize(n+1, false);	
				int src = nodes[i], des = nodes[j], init = values[nodes[i]];
				if(!visited[src] && dfs(src, des, visited, init)) cnt++;
			}
		}
		ans += cnt;
	}
	cout << ans;
	return 0;
}
