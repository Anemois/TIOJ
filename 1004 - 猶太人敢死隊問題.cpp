#include <bits/stdc++.h>
using namespace std;

int solve(int x){
    if(x == 1) return 1;
    if(x%2 == 0)
        return solve(x/2) * 2 - 1;
    else
        return solve(x/2) * 2 + 1;
}

int main(){
    int n;
    cin >> n;
    cout << solve(n);
}
