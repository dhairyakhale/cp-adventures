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

pair<int,int> retmax(vector<int> &execution) {
	int m1=INT_MIN,m1i,m2=INT_MIN,m2i, n=execution.size();
	for(int i=0;i<n;i++){

		if(execution[i] > m1){
			m2=m1;
			m2i = m1i;
			m1=execution[i];
			m1i = i;
		}
		else if(execution[i] > m2){
			m2 = execution[i];
			m2i = i;
		}

	}

	debug(m1,m2);

	return {m1i,m2i};
}

void solve(){
	int n; cin>>n;
	vector<int> execution(n);

	for(int i=0;i<n;i++)
		cin>>execution[i];

	int x,y; cin>>x>>y;
	
	pair<int,int> mx;
	mx = retmax(execution);

	int ans=0;
	int flag=1;
	while(execution[mx.f]>x && execution[mx.s]>y) {

		int c = ((execution[mx.f] - execution[mx.s]) / (x-y)) + 1;
		debug(c);

		if(c > (execution[mx.f]/x)){
			c = ceil(execution[mx.f]/x);
			ans += c;
			flag=0;
			break;
		}
		ans += c;

		for(int i=0;i<n;i++){
			if(i == mx.f)
				execution[i] -= c*x;
			else
				execution[i] -= c*y;
		}

		if(execution[mx.f]>0 || execution[mx.s]>0)
			mx = retmax(execution);
	}

	cout<<ans+flag;
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