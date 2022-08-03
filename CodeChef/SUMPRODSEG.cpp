
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

bool ok(ll mid, ll left, ll right, ll x){
	return mid < left && (x - mid) < left || mid > right && (x - mid) > right;
}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		ll x, y;
		cin >> x >> y;
		vector<pair<ll, ll>> factors;
		for(ll i=1; i*i<=y; ++i){
			if(y % i == 0){
				if(i * i == y){
					factors.push_back({i, i});
					break;
				}
				factors.push_back({i, y/i});
			}
		}

		// debug(factors);
		int flag = 0;
		for(int i=0; i<factors.size(); ++i){
			ll low = 0, high = 1;
			while(ok(high, factors[i].f, factors[i].s, x))
				high <<= 1;

			// debug(factors[i], low, high);
			while(high > low + 1){
				ll mid = low + (high - low)/2;
				if(ok(mid, factors[i].f, factors[i].s, x))
					low = mid;
				else
					high = mid; 
			}
			// debug(factors[i], low, high);
			if(ok(low, factors[i].f, factors[i].s, x)){
				flag = 1;
				cout << factors[i].f << " " << factors[i].s << "\n";
				cout << min(low , x - low) << " " << max(low, x - low) << "\n";
				break;
			}
		}

		if(!flag)
			cout << "-1\n";				
	}
	return 0;
}
