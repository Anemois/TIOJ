#include <bits/stdc++.h>
using namespace std;

int cut(int x){
    if(x==0) return 1;
    return x + cut(x-1);
}

int main(){
    int n;
    cin >> n;
    cout << cut(n);
}
