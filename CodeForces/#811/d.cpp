
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
		string txt;
		cin>>txt;
		int tsz = txt.size();

		int n;
		cin>>n;
		map<int,vector<pair<int,int>>> strv;
		for(int i=0;i<n;i++){
			string s;
			cin>>s;
			int sz = s.size();
			
			int l=0,r;
			pair<int,int> p = {-1,-1};
			while(l<=tsz-sz){
				if(txt[l] == s[0]){
					p.first=l;
					r=1;
					while(r<sz && txt[l+r]==s[r])
						r++;
					if(r==sz){
						p.second=r-1;
						strv[i].push_back(p);
					}
				}
				l++;
			}
		}

		for(int i=0;i<strv.size();i++){
			sort(strv[i].begin(),strv[i].end(),[](pair<int,int> p1, pair<int,int> p2){
				return p1.first < p2.first;
			});
		}
	}
	return 0;
}
