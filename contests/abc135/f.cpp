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
using pii = pair<Int,Int>;
using mapis = unordered_map<Int,string>;
using mapii = unordered_map<Int,Int>;

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

Int LCM(Int a, Int b){
    return a*b/GCD(a,b);
}


vi* dijkstra(int n, int start, int goal, vector<vector<pair<Int,Int>>> &edges){
    map<int,int>done;
    vi dist = vi(n+1,inf);
    vi prever = vi(n+1,-1);
    dist[start] = 0;

    priority_queue<pii, vector<pii>, greater<pii> > que;
    que.push(make_pair(start,0));

    while(!que.empty()){
        pii nowTo = que.top();
        que.pop();

        if(dist[nowTo.first]<nowTo.second){
            continue;
        }
        done[nowTo.first] = 1;

        for(int i=0;i<edges[nowTo.first].size();i++){
            pii e = edges[nowTo.first][i];
            if(dist[e.first] > dist[nowTo.first] + e.second){
                dist[e.first] = dist[nowTo.first] + e.second;
                prever[e.first] = nowTo.first;
                que.push(make_pair(dist[e.first],e.first));
            }
        }
    }
    return &prever;
}

int main() {
    Int N,Q;
    cin >> N >> Q;
    map<Int,map<Int,Int>> color;
    map<Int,map<Int,Int>> cost;

    vector<vector<pair<Int,Int>>> edges = vector<vector<pair<Int,Int>>>(N+1);

    rep(i,N-1){
        Int a,b,color_t,cost_t;
        cin >>a >>b >> color_t >> cost_t;
        edges[a].push_back(make_pair(b,cost_t));
        edges[b].push_back(make_pair(a,cost_t));
        color[a][b] = color_t;
        color[b][a] = color_t;
        cost[a][b] = cost_t;
        cost[b][a] = cost_t;
    }

    cout << ans << endl;

    return 0;
}