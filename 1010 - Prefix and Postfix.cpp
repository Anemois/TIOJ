#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

void solve(){
    string s, e;
    cin >> s >> e;
    int sh, sm, ss, eh, em, es;
    sh = (s[0]-'0')*10 + (s[1]-'0');
    sm = (s[3]-'0')*10 + (s[4]-'0');
    ss = (s[6]-'0')*10 + (s[7]-'0');
    eh = (e[0]-'0')*10 + (e[1]-'0');
    em = (e[3]-'0')*10 + (e[4]-'0');
    es = (e[6]-'0')*10 + (e[7]-'0');
    es -= ss;
    if(es < 0){
        em--;
        es+=60;
    }
    em -= sm;
    if(em < 0){
        eh--;
        em+=60;
    }
    eh -= sh;
    if(eh < 0){
        eh+=24;
    }
    if(eh < 10)
        cout << "0";
    cout << eh << ":";
    if(em < 10)
        cout << "0";
    cout << em << ":";
    if(es < 10)
        cout << "0";
    cout << es;
}

int main(){
	Anemoi
    solve();
	return 0;
}
