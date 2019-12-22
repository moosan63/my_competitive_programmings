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
    Int N,M;
    int ans = 0;
    cin >> N >> M;

    vector<char> names;
    set<char> name;
    set<char> kit;
    map<char,int> name_bag;
    map<char,int> kit_bag;

    rep(i,N){
        char n;
        cin >> n;
        name.insert(n);
        name_bag[n]++;
    }


    rep(i,M){
        char m;
        cin >> m;
        kit.insert(m);
        kit_bag[m]++;

    }

    for(auto itr = name.begin(); itr != name.end(); ++itr) {
        if (kit_bag[*itr]==0){
            cout << -1 << endl;
            return 0;
        }

        int count, amari;
        count = name_bag[*itr]/kit_bag[*itr];
        amari = name_bag[*itr]%kit_bag[*itr];

        if(amari==0){
            ans = max(count, ans);
        }else{
            ans = max(count+1,ans);
        }
    }


    cout << ans << endl;




    return 0;
}