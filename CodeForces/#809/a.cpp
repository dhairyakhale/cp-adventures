
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
		int n,m;
		cin>>n>>m;

		vector<int> nv(n);

		for(int i=0;i<n;i++){
			cin>>nv[i];
		}

		string s="";
		for(int i=0;i<m;i++)
			s += "B";

		for(int i=0;i<n;i++){

			int x = (m+1-nv[i]);
			if(nv[i]-1 <= x-1){
				if(s[nv[i]-1]=='A')
					s[x-1] = 'A';
				else
					s[nv[i]-1] = 'A';
			}
			else{
				if(s[x-1]=='A')
					s[nv[i]-1] = 'A';
				else
					s[x-1] = 'A';
			}
		}

		cout<<s<<'\n';
	}
	return 0;
}
