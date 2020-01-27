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
Int MOD = 1000000000+7;

int main() {
    Int H,N;
    cin >> H >> N;
    vector<pii> magics;
    mapii max_b;

    rep(i,N){
        Int a,b;
        cin >> a >> b;
        magics.emplace_back(make_pair(a,b));
    }

    sort(magics.begin(),magics.end());

    vi HP = vi(H+1,10000000000LL);

    HP[1] = magics[0].second;

    REP(i,1,H+1){
        rep(j,N){
            int cand;
            if(i<=magics[j].first){
                HP[i] = min(HP[i], magics[j].second);
            }else{
                cand = i-magics[j].first;
                HP[i] = min(HP[i], HP[cand]+magics[j].second);
            }


        }
    }

    cout << HP[H] << endl;

    return 0;
}