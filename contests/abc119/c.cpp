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
    Int N,A,B,C, ans;
    cin >> N >> A >> B >> C;
    ans = 0;

    vi l = vi(N,0);
    vi done = vi(N,0);
    rep(i,N){
        cin >> l[i];
        done[i] =0;
    }

    vi abc;
    abc.push_back(A);
    abc.push_back(B);
    abc.push_back(C);

    while(!abc.empty()){
        Int amin=10000,bmin=10000,cmin=10000;
        rep(i,abc.size()){
            rep(j,N){
                Int diff = abs(abc[i]-l[j]);
                amin = min(diff,amin);
            }
        }
    }

    return 0;
}