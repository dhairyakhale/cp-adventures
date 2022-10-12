#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> energy, coins;
vector<vector<int>> dp;
int n, ans;

/*
5 1
1 5 3 3 1
3 23 9 2 2

3 0
2 1 1
11 5 7
*/
int fun(int pos, int current_energy, int current_coins) {
    //debug(pos, current_energy, current_coins);

    if (pos == n || current_energy < 0)
        return current_coins;

    if (dp[pos][current_energy] != -1)
        return dp[pos][current_energy];

    int a = fun(pos + 1, current_energy + energy[pos] - 1, current_coins);
    int b = fun(pos + 1, current_energy - 1, current_coins + coins[pos]);

    return dp[pos][current_energy] = max(a, b);
}

void solve() {
    energy.clear();
    coins.clear();
    dp.clear();
    ans = 0;


    cin >> n;
    int initial;
    cin >> initial;


    energy.resize(n, 0);
    coins.resize(n, 0);
    dp.resize(n + 1, vector<int>(1001, -1));

    for (int i = 0; i < n; i++)
        cin >> energy[i];
    for (int i = 0; i < n; i++)
        cin >> coins[i];


    cout << fun(0, initial, 0);
    // debug(dp);
}

int main()
{
    std::ios::sync_with_stdio(false);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}