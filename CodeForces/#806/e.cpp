
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

		string mat[n];
		for(int i=0;i<n;i++){
			cin>>mat[i];
		}

		int c0,c1;
		int ans=0;

		for(int i=0;i<(n/2);i++){
			for(int j=0;j<(n/2);j++){
				c0=0,c1=0;

				if(mat[i][j]=='0')
					c0++;
				else
					c1++;

				if(mat[n-i-1][j]=='0')
					c0++;
				else
					c1++;

				if(mat[i][n-j-1]=='0')
					c0++;
				else
					c1++;

				if(mat[n-i-1][n-j-1]=='0')
					c0++;
				else
					c1++;

				if(c0>c1){
					if(mat[i][j]=='1'){
						mat[i][j]=='0';
						ans++;
					}
					if(mat[n-i-1][j]=='1'){
						mat[n-i-1][j]=='0';
						ans++;
					}

					if(mat[i][n-j-1]=='1'){
						mat[i][n-j-1]=='0';
						ans++;
					}

					if(mat[n-i-1][n-j-1]=='1'){
						mat[n-i-1][n-j-1]=='0';
						ans++;
					}
				}
				else {
					if(mat[i][j]=='0'){
						mat[i][j]=='1';
						ans++;
					}
					if(mat[n-i-1][j]=='0'){
						mat[n-i-1][j]=='1';
						ans++;
					}

					if(mat[i][n-j-1]=='0'){
						mat[i][n-j-1]=='1';
						ans++;
					}

					if(mat[n-i-1][n-j-1]=='0'){
						mat[n-i-1][n-j-1]=='1';
						ans++;
					}
				}
			}
		}

		int mid;
		if(n%2){
			mid = n/2;

			for(int i=0;i<mid;i++){
				
				c0=0,c1=0;

				if(mat[i][mid] == '0')
					c0++;
				else
					c1++;

				if(mat[mid][i] == '0')
					c0++;
				else
					c1++;

				if(mat[n-i-1][mid] == '0')
					c0++;
				else
					c1++;

				if(mat[mid][n-i-1] == '0')
					c0++;
				else
					c1++;

				if(c0<c1){
					if(mat[i][mid] == '0'){
						mat[i][mid] == '1';
						ans++;
					}
					if(mat[n-i-1][mid] == '0'){
						mat[n-i-1][mid] == '1';
						ans++;
					}
					if(mat[mid][i] == '0'){
						mat[mid][i] == '1';
						ans++;
					}
					if(mat[mid][n-i-1] == '0'){
						mat[mid][n-i-1] == '1';
						ans++;
					}
				}
				else {
					if(mat[i][mid] == '1'){
						mat[i][mid] == '0';
						ans++;
					}
					if(mat[n-i-1][mid] == '1'){
						mat[n-i-1][mid] == '0';
						ans++;
					}
					if(mat[mid][i] == '1'){
						mat[mid][i] == '0';
						ans++;
					}
					if(mat[mid][n-i-1] == '1'){
						mat[mid][n-i-1] == '0';
						ans++;
					}
				}
			}
		}

		cout<<ans<<"\n";
	}
	return 0;
}
