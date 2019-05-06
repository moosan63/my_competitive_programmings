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
    Int ans;
    cin >> N;

    vi A = vi(N);
    rep(i,N){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    Int min_a = A[0];
    int now_i = 0;
    rep(i,N){
        if(now_i == i) continue;
        if(min_a == 1){
            ans =1;
            break;
        }
        Int amari = A[i]%min_a;
        if(amari == 1){
            ans = 1;
            break;
        }
        if(amari != 0){
            A[i]=amari;
            min_a = min(amari,min_a);
            ans = min_a;
            now_i = i;
            i = -1;
        }
        if(amari == 0){
            ans = min_a;
        }
    }

    cout << ans;
    return 0;
}