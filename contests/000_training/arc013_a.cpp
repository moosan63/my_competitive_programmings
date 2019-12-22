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
    Int N,M,L,P,Q,R;
    cin >> N >> M >> L >> P >> Q >> R;


    int ans1 = (N/P)*(M/Q)*(L/R);
    int ans1_2 = (N/P)*(M/R)*(L/Q);
    int max1 = max(ans1,ans1_2);

    int ans2 = (N/Q)*(M/R)*(L/P);
    int ans2_2 = (N/Q)*(M/P)*(L/R);
    int max2 = max(ans2,ans2_2);

    int ans3 = (N/R)*(M/P)*(L/Q);
    int ans3_2 = (N/R)*(M/Q)*(L/P);
    int max3 = max(ans3,ans3_2);

    cout << max(max1,max(max2,max3)) << endl;


    return 0;
}