
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
	cin.tie(NULL);

	int T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		int n;
		cin>>n;

		ll dp[n+2][2];

		dp[n+1][0] = dp[n+1][1] = 1;

		ll o1,o2,o3,o4;

		for(int i=n;i>=2;i--){

			o1 = (dp[i+1][0]+dp[i+1][1]) % mod;
			o2 = dp[i+1][0];
			o3 = (2*dp[i+1][0]) % mod;
			o4 = dp[i+1][1];

			dp[i][0] = (o1+o2+o3)%mod;
			dp[i][1] = (o4+o1)%mod;
		}

		cout<<(dp[2][0]+dp[2][1])%mod<<'\n';
	}
	return 0;
}
