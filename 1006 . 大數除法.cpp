#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

int big_minus(vector<int>& n1, vector<int>& n2, int k){
    if(k >= n1.size()) return 0;
    int cnt=0, n = n2.size();
    vector<int> vect = n1;
    while(1){
        for(int i=k, j=1; i>k-n; i--, j++){
            vect[i] -= n2[n-j];
            if(vect[i] < 0){
                if(i == k-n+1 && (i == 0 || vect[i-1] <= 0)){
                    return cnt;
                }
                else{
                    vect[i-1]--;
                    vect[i] += 10;
                }
            }
        }
        cnt++;
        n1 = vect;
    }
}

void solve(){
    string a, b;
    cin >> a >> b;
    vector<int> n1(a.length()), n2(b.length());
    for(int i=0; i<a.length(); i++)
        n1[i] = a[i] - '0';
    for(int i=0; i<b.length(); i++)
        n2[i] = b[i] - '0';
    
    string ans;
    for(int i=b.length()-1; i<a.length(); i++){
        ans += big_minus(n1, n2, i) + '0';
    }
    if(ans.length() == 0)
        cout << "0";
    else{
        bool seen = false;
        for(int i=0; i<ans.length(); i++){
            if(ans[i] != '0')
                seen = true;
            if(seen)
                cout << ans[i];
        }
    }
}
int main(){
    Anemoi
    solve();
}
