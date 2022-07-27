
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

bool strcheck(string s, set<string> &strset){

	int n = s.size();
	string temp = "";
	for(int i=0;i<n;i++){
		temp += s[i];
		if(strset.find(temp)!=strset.end() && strset.find(s.substr(i+1,n))!=strset.end())
			return true;
	}

	return false;
}
int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		int n; cin>>n;

		string s;
		set<string> strset;
		vector<string> vstr;
		for(int i=0;i<n;i++){
			cin>>s;
			vstr.push_back(s);
			strset.insert(s);
		}
		for(auto a : vstr){

			if(strcheck(a,strset))
				cout<<1;
			else
				cout<<0;
		}
		cout<<"\n";
	}
	return 0;
}
