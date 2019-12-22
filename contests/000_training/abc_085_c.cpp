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
    Int N, Y;

    cin >> N >> Y;

    rep(i,N+1){
        rep(j,N+1){
            if(i+j<=N){
                Int z =Y-i*1000-j*5000;
                int zc = z/10000;
                if(z%10000 == 0 && z>=0 && zc+i+j == N){
                    cout << z/10000 << " " << j << " " << i << endl;
                    return 0;
                }
            }
        }
    }

    cout << -1 << " " << -1 << " " << -1 << endl;




    return 0;
}