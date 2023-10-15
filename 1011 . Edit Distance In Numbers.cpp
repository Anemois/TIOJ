#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);

using namespace std;

typedef long long ll;

int solve(){
    int a, b, cnt=0;
    cin >> a >> b;
    while(a != b){
        if(a > b)
            a/=2;
        else
            b/=2;
        cnt++;
    }
    return cnt;
}

int main(){
    cout << solve();
    return 0;
}