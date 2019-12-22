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
    Int N;

    cin >> N;

    vvi done = vvi(N,vi(N));
    vector<pii> points;
    rep(i,N){
        Int x,y;
        cin >> x >> y;
        points.push_back(make_pair(x,y));
    }

    double ans = 0;
    rep(i,N){
        rep(j,N){
            if(i==j) continue;
            double x_l = pow((points[i].first - points[j].first),2);
            double y_l = pow((points[i].second - points[j].second),2);
            double candidate = sqrt(x_l+y_l);

            ans = max(candidate, ans);

        }
    }

    cout <<std::fixed<< setprecision(10) <<  ans << endl;




    return 0;
}