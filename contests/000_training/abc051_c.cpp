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
    Int sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;

    int dx = tx-sx;
    int dy = ty-sy;

    // Path 1
    cout << string(dy,'U') << string(dx,'R');

    // Path 2
     cout << string(dy,'D') << string(dx,'L');

     // Path 3
     cout << 'L' << string(dy+1,'U') << string(dx+1,'R') << 'D';

     // Path 4
     cout << 'R' << string(dy+1,'D') << string(dx+1,'L') << 'U';

     // EndLine
     cout << endl;


    return 0;
}