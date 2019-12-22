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
    Int N,Q;
    cin >> N >> Q;

    // いもす法
    vi board = vi(N);

    // 加算
    rep(i,Q){
        int l,r;
        cin >> l >> r;
        board[l-1]++;
        if(r==N){
            continue;
        }
        board[r]--;
    }

    //構築
    vi imos_result = vi(N);

    imos_result[0]=board[0];
    REP(i,1,N){
        imos_result[i]=imos_result[i-1]+board[i];
    }


    rep(i,N){
        if(imos_result[i]%2==0){
            cout << 0;
        }else{
            cout << 1;
        }
    }
    cout << endl;


    return 0;
}