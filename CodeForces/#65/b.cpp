//UPSOLVE

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
	int T=1;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		int n,k,t;
		cin>>n>>k>>t;

		vector<int> ans(n,0);

		int sqs = n*k*t/100;

		int i;
		for(i=0;sqs>=k;i++){
			ans[i] = k;
			sqs -= k;
		}

		if(sqs>0)
			ans[i] = sqs;

		for(auto a : ans)
			cout<<a<<" ";
	}
	return 0;
}
