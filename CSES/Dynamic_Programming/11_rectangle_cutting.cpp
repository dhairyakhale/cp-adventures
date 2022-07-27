
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
		
		int a,b;

		cin>>a>>b;

		int ans;

		vector<vector<int>> dp(a+1,vector<int>(b+1,0));

		for(int i=1;i<=a;i++){
			for (int j=1; j<=b; j++)
			{
				if(i==j)
					dp[i][j] = 0;
				else {
					ans = 1e8;
					for(int k=1;k<j;k++)
						ans = min(ans,1+dp[i][k]+dp[i][j-k]);
					for(int k=1;k<i;k++)
						ans = min(ans,1+dp[k][j]+dp[i-k][j]);
					dp[i][j] = ans;
				}
			}
		}
		
		cout<<dp[a][b];
		
		return 0;
	}
