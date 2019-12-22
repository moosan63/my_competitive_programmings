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

int main() {
    Int N,M,S,T;
    cin >> N >> M;
    map<pii,vector<pii>> node;
    int from, to;
    rep(i,M){
        cin >> from >> to;

        // フェーズ付きに拡張してグラフを作る
        node[make_pair(from,0)].push_back(make_pair(to,1));
        node[make_pair(from,1)].push_back(make_pair(to,2));
        node[make_pair(from,2)].push_back(make_pair(to,0));
    }
    cin >> S >> T;

    int ans =0;

    queue<pii> next;
    map<int,map<int,int>> done;
    map<int,map<int,int>> route;
    next.push(make_pair(S,0));


    // BFSで回す
    while(!next.empty()){
        pii now = next.front();
        next.pop();
        if(done[now.first][now.second] == 1 ){
            continue;
        }

        done[now.first][now.second] = 1;

        rep(i,node[now].size()){
            pii next_node = node[now][i];
            next.push(node[now][i]);
            route[next_node.first][next_node.second] = route[now.first][now.second]+1;
        }

        if(now.first==T && now.second==0){
            break;
        }
    }

    if(done[T][0]==0){
        ans = -1;
    }else{
        ans = route[T][0]/3;
    }

    cout << ans << endl;

    return 0;
}