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

void dfs(int i, int par, vector<bool>&visited, vector<vector<int>>&adj)
{
	if(visited[i] == true)
	{
		visited[par] = true;
		return;
	}
	for(int j : adj[i])
	{
		dfs(j,i,visited,adj);
	}
}

void solve(){
	int n, p, projects, temp;
	cin >> n >> p;
	vector<vector<int>> adj(n+1);

	for(int i = 1; i <= n; i++) {
		cin >> temp;
		adj[i].push_back(temp);
	}

	vector<bool>visited(n+1,false);
	visited[0] = true;
	
	for(int i=0; i<p; i++)
	{
		cin >> projects;
		dfs(projects,projects,visited,adj);
	}

	for(int i=1; i<=n; i++)
	{
		if(visited[i] == false)
			cout << i << " ";
	}
}

int main()
{	
	std::ios::sync_with_stdio(false);
	int T=1; 
	// cin >> T;
	while(T--){
		solve();
	}
	return 0;
}

// N employees are given having ids from 1 to N. Then there is an array given a[N] in which every ith entry corresponds to who is superior of ith employees. Now there are p projects and a single employee is working on a single project. For every project, some bonus is given to the manager that is as high in hierarchy as possible and hasn't gotten a bonus. We had to find at the end which employees didn't get a bonus. 
// For Ex. Suppose the case is
// 8 4
// 0 1 1 2 3 3 4 4
// 8 4 6 5
// Here 0 represents the CEO of company and he isn't included in the bonus scheme. 
// In this case the ans would be 4 6 7 8 and you can see it by making the tree.
// Btw by hierarchy I mean if X reports to Y and Y reports to Z with X being working on a project, then Z would get the bonus first if he hasn't gotten it yet