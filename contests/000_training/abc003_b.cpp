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
    string s,t;
    cin >> s >> t;
    map<char,int> atcoder;

    string flags = "atcoder";
    rep(i,flags.size()){
        atcoder[flags[i]]++;
    }


    rep(i,s.size()){
        if(s[i]==t[i]){
            continue;
        }

        if(s[i]=='@'){
            if(atcoder[t[i]]){
                continue;
            }
        }

        if(t[i]=='@'){
            if(atcoder[s[i]]){
                continue;
            }
        }


        cout << "You will lose" << endl;
        return 0;
    }


    cout << "You can win" << endl;
    return 0;
}