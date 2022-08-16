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
	int T;
	cin>>T;
	// cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
		int m; cin>>m;

		vector<vector<int>> arr(2,vector<int>(m,0));

		int maxe=INT_MIN,maxi,maxj;
		for(int i=0;i<2;i++){
			for (int j = 0; j < m; ++j)
			{
				cin>>arr[i][j];
				if(arr[i][j]>maxe){
					if(arr[i][j]==maxe && i==1)
						maxi=i;
					maxe=arr[i][j];
					maxi=i;
					maxj=j;
				}
			}
		}

		int ctr=0;
		bool flag=false;

		if(maxj==m-1){
			cout<<max(2*m-1,maxe+1)<<endl;
			continue;
		}
		
		int i=0,j=0;
		while(!flag){
			if((i+1)%2==maxi && (j==maxj || j+1==maxj)){
				flag=true;
				ctr += 2*(m-j+1)+1;
				ctr = max(ctr,maxe+1);
				cout<<ctr<<endl;
			}
			else{
				arr[i][j]=-1;
				if(i==0){
					if(ctr<arr[i+1][j])
						ctr += 1+arr[++i][j];
					else{
						i++;
						ctr++;
					}
				}
				else{
					if(ctr<arr[i][j+1])
						ctr += 1+arr[i][++j];
					else{
						j++;
						ctr++;
					}
				}
			}
		}
	}
	return 0;
}
