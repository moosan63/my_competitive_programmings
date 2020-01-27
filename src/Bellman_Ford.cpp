//
// ベルマンフォードの実装おきば
//

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
using mapis = unordered_map<Int,string>;
using mapii = unordered_map<Int,Int>;
using pii = pair<Int,Int>;

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

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main() {
    Int N,M;
    cin >> N >> M;

    // 頂点[i]はいくつかの[to,cost]の辺を持つ
    // usingで定義したら楽そう
    vector<vector<pair<Int,Int>>> edges = vector<vector<pair<Int,Int>>>(N+1);
    vector<Int> cost = vi(N+1,inf);

    // スタート地点のコストは0
    cost[1] = 0;

    // 初期化
    rep(i,M){
        Int a,b,c;
        cin >>a >>b >>c;
        // ここを -c にすると最短経路じゃなくて最長経路を求められる
        edges[a].push_back(make_pair(b,c));
    }

    // ループ検出
    bool is_loop = false;

    // 経路たどり
    vi pre = vi(N+1);

    REP(i,1,N+1){
        REP(j,1,N+1){
            rep(k,edges[j].size()){
                pii now = edges[j][k];
                // 行き先のコスト > 今のとこまでのコスト+行き先までの辺のコスト
                if(cost[j] != inf && cost[now.first] > cost[j] + now.second ){
                    cost[now.first] = cost[j]+now.second;
                    pre[now.first] = j;
                    // iがN(頂点数)を超えるってことは、どこかに負の総和のループがある
                    if (i == N) {
                        is_loop = true;
                        break;
                    }
                }
            }
        }
    }

    // このチェックは、あるstartからgoalまでの間に限って負の経路があるかを調べる
    int check = N;
    for(int i = N; i>0; i--){
        check = pre[check];
        if(check == 0) break;
    }

    // 全体に負の経路が混じってる && それが今回調べたいゴール地点の間にあるかどうか
    if(is_loop && check!=0){
        cout << "inf" << endl;
    }else{
        // Nまでの最短経路のコストを出せる
        cout << cost[N] << endl;
    }


    return 0;
}