#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long ll;

int solve(){
    string p, q;
    cin >> p >> q;

    string s1, s2;
    int n1 = p.length(), n2 = q.length();
    int n = min(n1, n2), ans = 0;
    for(int i=0; i<n; i++){
        s1 += p[i];
        s2 = q[n2-i-1] + s2;
        if(s1 == s2)
            ans = i+1;
    }
    return ans;
}

int main(){
    cout << solve();
    return 0;
}