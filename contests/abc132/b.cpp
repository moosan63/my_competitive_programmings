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
int main() {
    int N;
    cin >> N;
    vi p = vi(N);

    rep(i,N){
        cin >> p[i];
    }
    int ans =0;

    REP(i,1,N-1){
        if(p[i-1] == p[i+1]){
            if (p[i-1] < p[i]){
                ans++;
            }
        }else if (p[i-1]>p[i+1]){
            if(p[i-1]>=p[i] && p[i]>p[i+1]){
                ans++;
            }
        }else if (p[i-1]<p[i+1]){
            if(p[i+1]>=p[i] && p[i]>p[i-1]){
                ans++;
            }
        }
    }


    cout << ans << endl;
    return 0;
}
