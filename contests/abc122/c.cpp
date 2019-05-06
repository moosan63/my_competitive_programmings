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

int main() {
    Int N, Q;
    string S;
    cin >> N >> Q;
    cin >> S;

    vi l = vi(Q);
    vi r = vi(Q);
    auto dp = vector<vector<Int>>(N+2,vector<Int>(N+2,0));

    rep(i,Q){
        cin >> l[i];
        cin >> r[i];
    }
    REP(i,1,N+1){
        for(int j = 1; j<N-i; j++){
            bool hasAC = S.substr(i,j) == "AC";
            if(hasAC){
                dp[i+1][j] = dp[i][j] + 1;
            }
            else{
                dp[i+1][j] = dp[i][j];
            }
        }

    }

    rep(i,Q){
    }
    return 0;
}