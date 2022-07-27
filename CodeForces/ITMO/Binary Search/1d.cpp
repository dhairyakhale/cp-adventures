
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
	int n; cin>>n;
	
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr.begin(),arr.end());

	int T; cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		int lval,rval;
		cin>>lval>>rval;

		int l=-1,r=n, l1,r1;

		while(l+1<r){
			int m = l+(r-l)/2;

			if(arr[m]<lval)
				l=m;
			else
				r=m;
		}
		l1=l+1;

		l=-1,r=n;

		while(l+1<r){
			int m = l+(r-l)/2;

			if(arr[m]<=rval)
				l=m;
			else
				r=m;
		}
		r1=r+1;
 
		int ans = r1-l1-1;

		cout<<ans<<"\n";
	}
	return 0;
}
