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

    Int ans=1;

    Int init = N;
    Int diff = -2;
    Int count;

    if(N%2==1){
        count = (N+1)/2;
    }else{
        count = N/2;
    }


    REP(i,1,count+1){
        Int m = init+(diff*(i-1));
        ans*=m;
    }

    cout << ans << endl;


    return 0;
}