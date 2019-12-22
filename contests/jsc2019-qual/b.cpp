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
Int printX(Int r, Int D, Int X, int count){
    if(count == 10){
        return 0;
    }
    Int nextX = r*X - D;
    cout<< nextX <<endl;
    printX(r,D,nextX,count+1);

}

int myPow(int x, int p) {
    if (p == 0) return 1;
    if (p == 1) return x;
    return x * myPow(x, p-1);
}

Int combination(Int n, Int r) {
    if ( r * 2 > n ) r = n - r;
    Int dividend = 1;
    Int divisor  = 1;
    for ( unsigned int i = 1; i <= r; ++i ) {
        dividend *= (n-i+1);
        divisor  *= i;
    }
    return dividend / divisor;
}

int main() {
    Int mod = 1000000000+7;
    Int N,K;
    cin >> N >> K;
    Int ans =0;
    vi A = vi(N*2);

    rep(i,N){
        cin >> A[i];
    }

    rep(i,N){
        REP(j,1,2){
            A[i+j*N]=A[i];
        }
    }

    // 自分の中だけで何個転倒があるか
    Int own = 0;
    rep(i,N){
        rep(j,N){
            if(i<j && A[i]>A[j]){
                own++;
            }
        }
    }

    // またぎの転倒が何個あるか
    Int over = 0;
    rep(i,N){
        REP(j,N,N*2){
            if(i<j && A[i]>A[j]){
                over++;
            }
        }
    }
    // 自分の中の転倒*K + またぎの転倒* (K Combination 2)
    ans = (own*K)+ (over*(K*(K-1)/2));
    ans = ans%mod;
    cout << ans << endl;



    return 0;
}
