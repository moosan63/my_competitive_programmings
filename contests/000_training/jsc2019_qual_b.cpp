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


int main() {
    Int N,K,count=0;
    Int mod=1000000000+7;
    cin >> N >> K;

    vi A = vi(N);

    rep(i,N){
        cin >> A[i];
    }

    rep(i,A.size()){
        Int tmp_count = 0;
        REP(j,i+1,A.size()){
            if(A[i]>A[j]){tmp_count++;}
        }
        count+=(tmp_count*K)%mod;
    }

    if (K>1){
        rep(i,A.size()){
            Int tmp_count = 0;
            REP(j,0,A.size()){
                if(A[i]>A[j]){tmp_count++;}
            }
            int hoge = K*(K-1)/2%mod;
            count+=((tmp_count)*hoge)%mod;
        }


    }


    cout << count%mod << endl;

    return 0;
}