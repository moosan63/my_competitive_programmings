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
Int MOD = 1000000000+7;

int main() {
    Int N;
    Int ans=0;
    cin >> N;

    vi A = vi(N);
    vvi Bs = vvi(N);
    rep(i,N){
        cin >> A[i];
    }

    Int now = A[0];
    REP(i,1,N){
        Int gcd = GCD(now,A[i]);
        Int lcm = (now*A[i])/gcd;

        REP(j,0,i){
            Bs[j].emplace_back((lcm/now)%MOD);
        }

        Bs[i].emplace_back((lcm/A[i])%MOD);
        now = lcm;
    }

    rep(i,N){
        Int tmp = 1;
        rep(j,Bs[i].size()){
            tmp*=Bs[i][j];
            tmp%=MOD;
        }
        ans+=tmp;
        ans%=MOD;

    }

    cout << ans << endl;




    return 0;
}