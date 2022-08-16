
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

//8
//-11 8 10 9 -19 -8 19 -14

using namespace std;

long long maximumMultiple(int N, int a[]){
	sort(a,a+N);

	for(int i=0;i<N;i++)
		cout<<a[i]<<" ";
	cout<<endl;

	if(a[N/2]>0 && a[(N/2)-1]<0)
	{
		long long maxans=INT_MIN;
		for(int i=0;i<N/2;i++){
			maxans = max(maxans,(long long )a[i]*a[N/2+i]);
		}
		return maxans;
	}

	return a[N/2]*a[(N/2)-1];
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T=1;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		int n; cin>>n;
		int a[n];

		for(int i=0;i<n;i++)
			cin>>a[i];

		cout<< maximumMultiple(n,a);
	}
	return 0;
}
