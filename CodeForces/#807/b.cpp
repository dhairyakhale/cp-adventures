
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
		int n; cin>>n;

		vector<ll> dust;

		for(int i=0;i<n;i++){
			int in; cin>>in;
			dust.push_back(in);
		}

		int i=0;
		while(i<n){
			if(dust[i]>0)
				break;
			i++;
		}

		if(i>=n-1){
			cout<<0<<'\n';
			continue;
		}

		int j=i+1;

		while(j<n && dust[j]>0)
			j++;

		ll moves=0;

		while(j<n-1){

			dust[i]--;
			dust[j]++;

			moves++;

			while(i<n-1 && dust[i]==0)
				i++;
			
			while(j<n-1 && dust[j]>0)
				j++;
		}

		for(i=0;i<n-1;i++)
			moves += dust[i];

		cout<<moves<<"\n";

	}
	return 0;
}