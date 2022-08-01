
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
bool stringcut(vector<int> &arr, int k, double cutlen){
	int cuts=0;
	for(auto a : arr)
		cuts += floor(a/cutlen);

	return cuts>=k;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;

	int k;
	cin>>k;

	std::vector<int> arr;
	double x,tlen=0;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--){
		cin>>x;
		tlen+=x;
		arr.push_back(x);
	}

	// cout<<tlen;

	double l=0,r=tlen,m;
	for(int i=0;i<100;i++) {
	    m=l+(r-l)/2;

	    if(stringcut(arr,k,m))
	    	l=m;
	    else
	    	r=m;
	}

	cout<<setprecision(20)<<l<<'\n';

	return 0;
}
