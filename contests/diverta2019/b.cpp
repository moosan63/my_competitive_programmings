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

int even_n(Int n) {
    return n/2;
}

int odd_n(Int n){
    return 3*n+1;
}

int main() {
    string S;

    cin >> S;
    Int ans =0;

    vi a;
    unordered_map<Int,Int> mp;
    mp[stoi(S)] = 1;
    a.push_back(0);
    a.push_back(stoi(S));
    REP(i,2,1000001){
        if(a[i-1]%2 == 0){
            a.push_back(even_n(a[i-1]));
        }else{
            a.push_back(odd_n(a[i-1]));
        }

        if(mp[a[i]] != 0){
            ans = i;
            break;
        }else{
            mp[a[i]] = i;
        }
    }


    cout << ans;
    return 0;
}