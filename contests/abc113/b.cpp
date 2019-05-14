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
    int N,T,A;

    cin >>N>>T>>A;
    Int ans =inf;
    vi H = vi(N);
    rep(i,N){
        cin >> H[i];
    }
    Int minT = inf;

    rep(i,N){
        Int tmp = T*1000-H[i]*6;
        Int now_diff = abs(A*1000-tmp);
        if(minT>now_diff){
            ans = i+1;
        }
        minT = min(minT,abs(A*1000-tmp)) ;
    }


    cout << ans;
    return 0;
}