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
    Int N;

    cin >> N;
    string ans;
    vi L = vi(N);
    rep(i,N){
        cin >> L[i];
    }
    sort(L.begin(), L.end(),greater<>());
    Int total =0;
    REP(i,1,N){
        total += L[i];
    }

    if(L[0] < total){
        ans = "Yes";
    }else{
        ans = "No";
    }

    cout << ans;
    return 0;
}