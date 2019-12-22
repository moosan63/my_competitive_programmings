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
    Int N;
    cin >> N;

    vi c = vi(N);

    rep(i,N){
        cin >> c[i];
    }

    vector<int> dp = vector<int>(N+1,9999999);
    dp[0]=c[0];

    REP(i,1,N){
        if (c[i] > dp[dp.size()-1]){
            dp[dp.size()] = c[i];
        }else{
            int next = lower_bound(dp.begin(),dp.end(), c[i])-dp.begin();
            dp[next] = c[i];
        }
    }

    int cand =0;
    REP(i,0,N){
        if(dp[i] == 9999999){
            break;
        }
        cand = i+1;
    }

    cout << N-cand << endl;

    return 0;
}