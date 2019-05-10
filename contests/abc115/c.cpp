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
    Int N,K;
    cin >> N>>K;
    vi H = vi(N);
    Int ans =inf;

    rep(i,N){
        cin >> H[i];
    }

    sort(H.begin(),H.end());
    Int tree_count = K-1;
    REP(i,tree_count,N){
        Int hmin = H[i-tree_count];
        Int hmax = H[i];
        ans = min(ans, hmax-hmin);
    }

    cout << ans << endl;
    return 0;
}