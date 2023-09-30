#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#define Anemoi ios_base::sync_with_stdio(false);cin.tie(0);
using namespace std;

int n, target;
vector<int> full;

bool possible(){
    int g = full[0], mx = full[0];
    for(int i=0; i<n; i++){
        mx = max(mx, full[i]);
        g = __gcd(g, full[i]);
    }
    if(target%g != 0 || target > mx)
        return false;
    
    return true;
}

string encode(vector<int>& v){
    string code;
    for(int i=0; i<n; i++)
        code = code + "#" + to_string(i) + to_string(v[i]);
    return code; 
}

bool check(vector<int>& v){
    for(auto& i : v)
        if(i == target)
            return true;
    return false;
}

int solve(){
    cin >> n;
    full.resize(n);
    for(int i=0; i<n; i++) cin >> full[i];
    cin >> target;
    if(! possible()) return -1;
    if(target == 0) return 0;
    vector<int> now(n, 0);

    unordered_set<string> vis;
    queue<vector<int>> pend;
    vis.insert(encode(now));
    pend.push(now);

    int cnt=1;

    while(!pend.empty()){
        int siz = pend.size();
        for(int o=0; o<siz; o++){
            now = pend.front(); pend.pop();
            
            //empty
            for(int i=0; i<n; i++){
                int t = now[i];
                now[i] = 0;
                string code = encode(now);
                if(vis.find(code) == vis.end()){
                    if(check(now))
                        return cnt;
                    vis.insert(code);
                    pend.push(now);
                }
                now[i] = t;
            }
            //fill
            for(int i=0; i<n; i++){
                int t = now[i];
                now[i] = full[i];
                string code = encode(now);
                if(vis.find(code) == vis.end()){
                    if(check(now))
                        return cnt;
                    vis.insert(code);
                    pend.push(now);
                }
                now[i] = t;
            }
            //to other
            vector<int> temp;
            for(int from=0; from<n; from++){
                for(int to=0; to<n; to++){
                    if(from == to) continue;
                    temp = now;
                    temp[to] += temp[from];
                    temp[from] = max(0, temp[to] - full[to]);
                    temp[to] = min(temp[to], full[to]);
                    string code = encode(temp);
                    if(vis.find(code) == vis.end()){
                        if(check(temp))
                            return cnt;
                        vis.insert(code);
                        pend.push(temp);
                    }
                }
            }
        }
        cnt++;
    }
    return -1;
}

int main(){
    Anemoi
    cout << solve();
}
