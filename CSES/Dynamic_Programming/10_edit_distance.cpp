
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
	
	string s1,s2;

	cin>>s1>>s2;

	int n1 = s1.size(), n2 = s2.size();

	vector<vector<int>> dp(n1+1, vector<int>(n2+1,0));

	for(int i=0;i<=n1;i++){
		dp[i][0] = i;
	}

	for(int i=0;i<=n2;i++){
		dp[0][i] = i;
	}

	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){

			if(s1[i-1] == s2[j-1])
				dp[i][j] = dp[i-1][j-1];
			else
				dp[i][j] = 1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
		}
	}

	int ans = dp[n1][n2];

	cout<<ans;

	return 0;
}
