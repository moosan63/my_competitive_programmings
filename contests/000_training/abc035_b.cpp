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
    string S;
    Int t;
    cin >> S >> t;

    mapii point_counts;
    rep(i,S.size()){
        point_counts[S[i]]++;
    }

    if(t==1){
        Int x = abs(point_counts['L']-point_counts['R']);
        Int y = abs(point_counts['U']-point_counts['D']);

        cout << x+y+point_counts['?'] << endl;
    }else{
        Int x = abs(point_counts['L']-point_counts['R']);
        Int y = abs(point_counts['U']-point_counts['D']);

        if( (x+y)>=point_counts['?'] ) {
            cout << x+y-point_counts['?'] << endl;
        }else{
            cout << (point_counts['?']-(x+y))%2 << endl;
        }

    }

    return 0;
}