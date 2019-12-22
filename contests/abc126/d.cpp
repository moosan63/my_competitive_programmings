#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define REP(i, b, n) for (Int i = b; i < Int(n); i++)
#define rep(i, n) REP(i, 0, n)
using namespace std;
using Int = long long;
Int inf = 1000000000000000001LL;
using vi = vector<Int>;
using vvi = vector<vi>;

Int GCD(Int a, Int b){
    if(b==0) return a;
    if(a < b) return GCD(b, a);
    unsigned r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}

 Int modinv(Int a, Int m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main() {
    Int N;
    cin >> N;
    vvi node_next = vvi(N+10);
    vi status = vi(N+2,0);
    int u,v,w;
    rep(i,N-1){
        cin >> u >> v >>w;
        node_next[u].push_back(v);
        node_next[v].push_back(u);
    }

    queue<int> next;
    next.push(1);
    vi done =vi(N+10);
    while(!next.empty()){
        int now = next.front();
        next.pop();
        rep(i,node_next[now].size()){
            int candidate = node_next[now][i];
            if(done[candidate]==1) continue;
            next.push(candidate);
            if (length[now][candidate]%2==0){
                status[candidate] = status[now];
            }else{
                if(status[now] == 0){
                    status[candidate] = 1;
                }else{
                    status[candidate] = 0;
                }
            }
        }
        done[now] =1;
    }

    REP(i,1,N+1){
        cout << status[i] <<endl;
    }

    return 0;
}