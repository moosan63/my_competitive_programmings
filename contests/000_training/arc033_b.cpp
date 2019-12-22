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
    Int A,B;

    cin >> A >> B;


    set<int> s;
    map<Int,Int> counts;
    rep(i,A){
        Int As;
        cin >> As;
        s.insert(As);
        counts[As]=1;
    }

    Int got = 0;
    rep(i,B){
        Int Bs;
        cin >> Bs;
        s.insert(Bs);
        if(counts[Bs]==1){
            got++;
        }
    }


    cout <<std::fixed<< setprecision(10) <<  (double)got/(double)s.size() << endl;


    return 0;
}