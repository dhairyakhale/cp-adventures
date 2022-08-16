
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

/*
5 3
4 2
2 3
3 4
1 5
2 7
*/
int main()
{
	std::ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> pairs(n, vector<int>(2));
	for(int i = 0; i < n; i++) {
		cin >> pairs[i][0] >> pairs[i][1];
	}

	sort(pairs.begin(), pairs.end(), [](vector<int>& a, vector<int>& b) {
		return a[1] > b[1];
	});

	priority_queue<int> q;
	
	int ans = INT_MIN;
	for(int i = 0; i < n - k + 1; i++) {
		int min_b = pairs[i + k - 1][1];
		for(int j = i; j < i + k; j++) {
			q.push(pairs[j][0]);
		}

		int cnt = 1, sum = 0;
		while(!q.empty()){
			// cout << ceil(k/(2.0));
			sum += cnt <= ceil(k/2.0) ? q.top() : -q.top();
			q.pop();
			cnt++;
		}

		ans = max(ans, sum * min_b);
	}


	cout << ans << endl;
	return 0;
}
