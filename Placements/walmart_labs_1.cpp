
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


// int solve(vector<int> a, vector<int> b, int k) {

// 	map<int,int> mp;

// 	priority_queue<pair<int,int>> pq;

// 	for(int i=0;i<a.size();i++)
// 		mp[a[i]]++;

// 	for(auto i : mp){
// 		pq.push({i.second,i.first});
// 	}

// 	if(pq.top().first == 1)
// 		return a.size();

// 	int ans=0;
// 	for(int i=0;i<b.size();i++){
// 		if(k>0 && mp.find(b[i]) == mp.end()){
// 			pair<int,int> temp = pq.top();
// 			pq.pop();

// 			temp.first--;
// 			pq.push(temp);
// 			pq.push({1,b[i]});
// 			mp[b[i]]=1;

// 			k--;

// 			if(pq.top().first == 1)
// 				break;

// 			if(k==0)
// 				break;
// 		}
// 		else
// 			break;
// 	}

// 	return mp.size();
// }


int solve(vector<int>& a, vector<int>& b, int k) {
	int n = a.size();

	unordered_map<int, int> ma, mb;
	for(int i = 0; i < n ; i++) {
		ma[a[i]]++;
		mb[b[i]]++;
	}

	for(auto& p : mb) {
		if(ma.count(p.first))
			mb.erase(p.first);
	}

	// if(mb.size() == 0) {
	// 	return ma.size();
	// }

	// vector<int> unique;
	// for(auto& p : mb)
	// 	unique.push_back(p.first);

	// // vector<pair<int, int>> pa(ma.size());
	// int ops = 0;
	// for(auto& p : ma) {
	// 	if(p.second > 1) {
			
	// 		while(p.second > 1 && ops <= k && ops < unique.size()) {
	// 			ma[unique[ops]]++;
	// 			ops++;
	// 			p.second--;
	// 		}
	// 	}
	// }
	
	// return ma.size();
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T = 1;
	// cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		int n;
		cin>>n;

		vector<int> a(n),b(n);

		for(int i=0;i<n;i++)
			cin>>a[i];
		for(int i=0;i<n;i++)
			cin>>b[i];

		int k;cin>>k;
		
		cout << solve(a,b,k);
	}
}
