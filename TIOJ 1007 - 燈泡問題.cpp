#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

vector<vector<long long>> dp;
int n, m;

long long go(int i, int t){
    if(dp[i][t] != 0)
        return dp[i][t];
    
    if(i == m)
        return dp[i][t] = 1;
    
    if(t == n)
        return dp[i][t] = go(i+1, 0);
    
    return dp[i][t] = go(i+1, t+1) + go(i+1, 0);
}

void solve(){
    cin >> n >> m;
    dp.resize(m+1, vector<long long>(n+1, 0));

    cout << go(0, 0);
}

int main(){
    Anemoi
    solve();
}
