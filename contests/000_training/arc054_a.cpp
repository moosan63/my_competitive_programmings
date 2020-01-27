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

Int count(Int n, Int x){
    if(n == -1){
        return 0;
    }

    return n/x +1;
}


int main() {
    long double L,X,Y,S,D;
    cin >> L >> X >> Y >> S >>D;

    long double ans;

    if(S==D){
        cout << 0 << endl;
        return 0;
    }

    if(S<D){
        if( X>=Y ){
            ans = (D-S)/(X+Y);
        }else{
            ans = min(((L-D)+S)/double(abs(Int(X)-Int(Y))), (D-S)/(X+Y));
        }

    }else{
        if( X>=Y ) {
            ans = ((L-S)+D)/(X+Y);
        }else{
            ans = min( ((L-S)+D)/(X+Y), (S-D)/double(abs(Int(X)-Int(Y))));
        }
    }



    cout <<std::fixed<< setprecision(10) <<  ans << endl;


    return 0;
}