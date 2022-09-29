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

int highestPowerof2(int n)
{
    int res = 0;
    for (int i = n; i >= 1; i--) {
        if ((i & (i - 1)) == 0) {
            res = i;
            break;
        }
    }
    return res;
}

void solve(){
	int n, k;
	cin >> n >> k;
	vector<int> a(n), p(n);
	for(int i =0; i < n; i++) {
		cin >> a[i] >> p[i];
	}

	vector<pii> given(n);
	for(int i = 0; i < n; i++)
		given[i] = {a[i], p[i]};

	sort(given.begin(), given.end());

	int ans = 0, val = 0, pos = -1, highest = highestPowerof2(k);
	for(int i = 0; i < n; i++) {
		if(given[i].first >= highest){
			pos = i;
			break;
		}
		ans += given[i].second;
		val |= given[i].first;
	}

	if(val <= (k ^ highest)) {
		int maxx = INT_MIN;
		for(int i = pos; i < n; i++) {
			maxx = max(maxx, given[i].second);
		}
		ans += maxx;
	}

	cout << ans << "\n";
	// cout << (13 & 12) << "\n";
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