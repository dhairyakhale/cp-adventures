
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
	int T, n;
	cin>>n>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];

	int tarr[T];
	for(int i=0;i<T;i++)
		cin>>tarr[i];

	int i=0;
	while(i<T)
	{

		int l=0,r=n-1,m;

		while(l<=r){
			m = l+(r-l)/2;

			if(arr[m] == tarr[i]){
				cout<<"YES\n";
				break;
			}

			if(arr[m]<tarr[i])
				l=m+1;
			else
				r=m-1;
		}
		if(l>r)
			cout<<"NO\n";
		i++;
	}
	return 0;
}
