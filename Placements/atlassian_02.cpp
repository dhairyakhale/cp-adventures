
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
void solve(int costPerCut, int salePrice, vector<int> lengths) {
	int max_profits = 0;

	for(int sale_length = 1; sale_length<=*max_element(lengths.begin(),lengths.end());sale_length++)
	{
		int sale_price_per_road=salePrice*sale_length;
		int profit=0;
		for(auto rod_length:lengths)
		{
			int uniform_rods=rod_length;
			if(uniform_rods>0)
			{
				int extra_cut;
				if(rod_length%sale_length>0)
					extra_cut=1;
				else
					extra_cut=0;
				int total_cuts=uniform_rods-1+extra_cut;
				int costs=total_cuts*costPerCut;
				int revenues=uniform_rods * sale_price_per_road;
				if(revenues>costs)
					profit+=revenues-costs;
			}
		}
		if(profit>max_profits)
			max_profits=profit;
	}
	return max_profits;
}
int main()
{
	std::ios::sync_with_stdio(false);
	solve();
	return 0;
}
