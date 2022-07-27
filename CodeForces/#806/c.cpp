
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

		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];

		int biarr[n];
		int moveval;

		string s;

		for(int i=0;i<n;i++){
			cin>>biarr[i];
			cin>>s;

			moveval=0;
			for(int j=0;j<biarr[i];j++){

				if(s[j] == 'U')
					moveval--;
				else
					moveval++;
			}

			if(moveval<0)
				arr[i] = (arr[i]+(10+moveval%10))%10;
			else
				arr[i] = (arr[i] + moveval%10)%10;
		}

		for(auto a : arr)
			cout<<a<<" ";

		cout<<"\n";
	}
	return 0;
}
