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
    int R,G,B,N;

    cin >>R>>G>>B>>N;
    Int ans =0;
    int r = N/R +1;
    int g = N/G +1;

    rep(i,r){
        rep(j,g){

            if( (N-(i*R+j*G))%B == 0 && i*R+j*G <= N ){
                ans++;
            }
        }
    }


    cout << ans;
    return 0;
}