
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
	int T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		int n,h,m;
		cin>>n>>h>>m;

		int t,ttemp,tmin=INT_MAX;
		t = h*60+m;

		while(n--){
			int h2,m2;
			cin>>h2>>m2;
			ttemp = h2*60+m2;
			
			if(ttemp<t)
				ttemp += 24*60;

			ttemp -= t;

			tmin = min(tmin,ttemp);
		}

		cout<<tmin/60<<" "<<tmin%60<<endl;
	}
	return 0;
}
