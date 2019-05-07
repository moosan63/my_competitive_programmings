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
    Int N,M;
    cin >> N>>M;
    Int ans =0;

    if(N<M){
        vi X = vi(M);
        rep(i,M){
            cin >> X[i];
        }

        sort(X.begin(), X.end());

        vi L;
        rep(i,M-1){
            L.push_back(X[i+1]-X[i]);
        }

        sort(L.begin(), L.end(), greater<>());
        Int Ltotal = 0;
        rep(i,N-1){
            Ltotal += L[i];
        }
        ans = (X[M-1]-X[0]) - Ltotal;
    }

    cout << ans;
    return 0;
}