
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
	
	int n;
	cin>>n;

	vector<int> ip_arr(n);
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>ip_arr[i];
		sum += ip_arr[i];
	}

	sort(ip_arr.begin(),ip_arr.end());

	vector<vector<int>> dp(n+1, vector<int>(sum+1,0));

	for(int i=0;i<n;i++){
		dp[i][0] = 1;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j-ip_arr[i-1] >= 0)
				dp[i][j] = dp[i-1][j] || dp[i-1][j-ip_arr[i-1]];
			else
				dp[i][j] = dp[i-1][j];
		}
	}

	int count=0;
	for(int i=1;i<=sum;i++){
		count += dp[n][i];
	}

	cout<<count<<'\n';

	for(int i=1;i<=sum;i++) {
		if(dp[n][i])
			cout<<i<<" ";
	}

	return 0;
}
