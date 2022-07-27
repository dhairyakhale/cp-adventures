
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

bool recur(int len, string s){

	if(len==1)
		return true;

	if(len == 2)
		return s[0] == s[1];

	if(len%2){
		s.pop_back();
		len--;
	}

	string s1 = s.substr(0,len/2), s2 = s.substr(len/2,len);

	if(s1!=s2)
		return false;

	return recur(len/2,s1);

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
		string s; cin>>s;

		recur(n,s) ? cout<<"YES\n" : cout<<"NO\n";		
	}
	return 0;
}
