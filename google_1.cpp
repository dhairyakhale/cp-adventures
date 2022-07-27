
#include <bits/stdc++.h>

#define mod 1000000007

using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	vector<string> words(n);
	for(int i=0; i<n; ++i){
		cin >> words[i];
	}

	int N = 0;
	vector<vector<pair<int, int>>> nxt((k+1)*n, vector<pair<int, int>>(26, {0, 0}));
	vector<bool> is_terminal(k+1, false);
	for(string word : words){
		int node = 0;
		for(char c : word){
			if(nxt[node][c-'a'].first == 0) nxt[node][c-'a'] = {++N, 1};
			else nxt[node][c-'a'].second++;
			// cout << nxt[node][c-'a'].first;
			node = nxt[node][c-'a'].first;
		}
		is_terminal[node] = true;
	}
	for(int i=0; i<n; ++i){
		int node = 0, ans = 0;
		for(char c : words[i]){
			ans = (ans + nxt[node][c-'a'].second) % mod;
			node = nxt[node][c-'a'].first;
		}
		cout << ans << " ";
	}
	return 0;
}
