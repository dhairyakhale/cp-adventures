
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
			int n;
		    cin >> n;
		    vector<int>arr(n);
		    for(int i=0; i<n; i++)
		        cin >> arr[i];


		    int maxDiff = 0 ; 
		    int index = -1 ; 
		    for(int i=  0 ; i < arr.size()-1 ; i++)
		    {
		        if(abs(arr[i]-arr[i+1]) >= maxDiff)
		        {
		           maxDiff = abs(arr[i]-arr[i+1]) ; 
		           index = i ; 
		        }
		    }
		    
		    int median = (arr[index] + arr[index+1]) / 2 ; 
		    
		   // int x = pow(arr[index] - median,2) + pow(median - arr[index+1],2) ; 
		    
		    int initialCost = 0 ;
		    
		    for(int i=  0 ; i < arr.size()-1 ; i++)
		        initialCost += pow(arr[i]-arr[i+1],2) ;
		    
		    initialCost = initialCost + pow(arr[index] - median,2) + pow(median - arr[index+1],2) - pow(arr[index] - arr[index+1] ,2) ; 
		    
		    cout << initialCost << endl;
		}
		return 0;
	}
