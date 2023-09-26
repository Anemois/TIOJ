#include <bits/stdc++.h>
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

int euclid(int a, int b){
    if(a < b) swap(a, b);
    if(a%b == 0) return b;

    return euclid(b, a%b);
}

void solve(int n){
    vector<int> vect(n);
    for(int i=0; i<n; i++){
        cin >> vect[i];
    }

    double cnt = 0;

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(euclid(vect[i], vect[j]) == 1){
                cnt++;
            }
        }
    }
    if(cnt == 0)
        cout << "No estimate for this data set.\n";
    else
        cout << fixed << setprecision(6) << sqrt(6*(n*(n-1)/2)/cnt) << "\n";
}

int main(){
    Anemoi
    int n;
    while(1){
        cin >> n;
        if(n == 0){
            break;
        }
        solve(n);
    }
}
