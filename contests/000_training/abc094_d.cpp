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
#include <math.h>
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

void comb(vvi &v){
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
        }
    }
}

int main() {
    Int n;
    cin >> n;

    vi A = vi(n);

    rep(i,n){
        cin >> A[i];
    }

    sort(A.begin(),A.end());

    Int candidate = A[A.size()-1];
    A.pop_back();

    vvi comb_ans = vvi(candidate+1, vi(A[A.size()-1]+1,0));
    comb(comb_ans);

    Int value=-1;
    Int ans;

    rep(i,A.size()){
        if(value<comb_ans[candidate][A[i]]){
            value = comb_ans[candidate][A[i]];
            ans = A[i];
        }
    }

    cout << candidate << " " << ans << endl;


    return 0;
}