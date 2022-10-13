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
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second

using namespace std;

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	
	vector<vector<pair<ll, ll>>> adj(n + 1);
	vector<ll> distance(n + 1, LLONG_MAX);
	vector<pair<ll, ll>> costs(k);

	for(int i = 0; i < k; i++) {
		int x, cx;
		cin >> x >> cx;
		costs[i] = {x, cx};
	}

	for(int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}

	auto cmp = [](pair<ll, ll>& a, pair<ll, ll>& b) {
		return a.second > b.second;
	};

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> pq(cmp);

	for(int i = 0; i < k; i++) {
		distance[costs[i].f] = costs[i].s;
		pq.push({costs[i].f, costs[i].s});
	}

	while(!pq.empty()) {
		auto current = pq.top();
		pq.pop();
		if(current.s > distance[current.f]) continue;
		
		for(auto next : adj[current.f]) {
			if(distance[next.f] > distance[current.f] + next.s) {
				distance[next.f] = distance[current.f] + next.s;
				pq.push({next.f, distance[next.f]});
			}
		}
	}

	for(int i = 1; i <= n; i++)
		cout << distance[i] << " ";
	cout << "\n";
}

int main()
{	
	std::ios::sync_with_stdio(false);
	int T=1; 
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}