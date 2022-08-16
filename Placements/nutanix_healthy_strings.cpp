
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

int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> first(26), last(26);

	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;
		first[s[0]-'a'].push_back(i);
		last[s.back()-'a'].push_back(i);
	}

	vector<vector<int>> adj(n);
	vector<int> indegree(n);
	for(int i = 0; i < 26; i++) {
		for(int l : last[i]) {
			for(int f : first[i]) {
				if(f > l) {
					adj[l].push_back(f);
					indegree[f]++;
				}
			}
		}
	}

	queue<int> q;
	for(int i = 0; i < n; i++) {
		if(!indegree[i])
			q.push(i);
	}
	
	int ans = 0;
	while(!q.empty()) {
		q.push(-1);
		while(q.front() != -1) {
			int u = q.front();
			q.pop();
			for(int v : adj[u]) {
				indegree[v]--;
				if(indegree[v] == 0)
					q.push(v);
			}
		}
		ans++;
		q.pop();
	}

	cout << ans << endl;
	return 0;
}
