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

void solve(){
	int n; cin >> n;
	unordered_map<string, int> m;
	m["Jan"] = 1;
	m["Feb"] = 2;
	m["Mar"] = 3;
	m["Apr"] = 4;
	m["May"] = 5;
	m["Jun"] = 6;
	m["Jul"] = 7;
	m["Aug"] = 8;
	m["Sep"] = 9;
	m["Oct"] = 10;
	m["Nov"] = 11;
	m["Dec"] = 12;

	vector<vector<string>> a(n, vector<string>(3));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}

	sort(a.begin(), a.end(), [&](vector<string>& sa, vector<string>& sb) {
		if(sa[2] == sb[2] && sa[1] == sb[1]) return sa[0] < sb[0];
		if(sa[2] == sb[2]) return m[sa[1]] < m[sb[1]];
		return sa[2] < sb[2];
	});

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++)
			cout << a[i][j] << " ";
		cout << "\n";
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