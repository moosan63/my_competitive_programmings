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

int ctoi(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return 0;
}

string ansS ="";

void plus_ans(int source, int adder, int l, string now, string &s){
    if (l == 3){
        if(source == 7){
            ansS = now+"=7";
        }
        return ;
    }

    plus_ans(source+adder, s[l+1], l+1,now+"+"+s[l+1],s);
    plus_ans(source-adder, s[l+1], l+1,now+"-"+s[l+1],s);
}

int main() {
    string S;
    cin >> S;

    plus_ans(ctoi(S[0]), S[1], 1,S[0]+"+"+S[1],S);
    plus_ans(ctoi(S[0]), ctoi(S[1]), 1,S[0]+"-"+S[1],S);


    cout << ansS << endl;


    return 0;
}