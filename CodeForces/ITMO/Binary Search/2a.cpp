
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
bool fn(ll x, ll a, ll b, ll n){
	return floor(x/a)*floor(x/b) >= n;
}
int main()
{
	std::ios::sync_with_stdio(false);
	ll w,h,n;
	cin>>w>>h>>n;

	ll l=0,r=max(w,h)*n;

	while(l+1<r){
		ll m = l+(r-l)/2;

		if(fn(m,w,h,n))
			r=m;
		else
			l=m;

	}

	cout<<r;
	return 0;
}
