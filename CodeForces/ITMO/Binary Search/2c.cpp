
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
bool fn(ll m, ll x, ll y, ll n){
	if(m < min(x,y))
		return false;

	m -= min(x,y);

	return (1+(m/x)+(m/y) >= n);
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll T=1;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		ll n,x,y; cin>>n>>x>>y;
		ll l=0,r=1;

		while(!fn(r,x,y,n))
			r <<= 1;

		while(l+1<r){
			ll m = l+(r-l)/2;

			if(fn(m,x,y,n))
				r=m;
			else
				l=m;
		}

		cout<<r;
	}
	return 0;
}
