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
    string Sd,T;
    vector<string> candidates;

    cin >> Sd >> T;

    rep(i,Sd.size()-T.size()+1){
        bool match = true;
        rep(j,T.size()){
            if(Sd[i+j]!=T[j] && Sd[i+j] != '?'){
                match = false;
                break;
            }
        }
        if(match){
            string tmpS;
            rep(j,Sd.size()){
                if(i==j){
                    tmpS+=T;
                    j+=T.size()-1;
                }else{
                    if(Sd[j]=='?'){
                        tmpS+= 'a';
                    }else{
                        tmpS+= Sd[j];
                    }
                }
            }
            candidates.push_back(tmpS);
        }
    }

    if(candidates.empty()){
        cout << "UNRESTORABLE" << endl;
    }else{
        sort(candidates.begin(),candidates.end());
        cout << candidates[0] << endl;
    }

    return 0;
}