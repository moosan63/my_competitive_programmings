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

int main() {
    int N;
    vector<double> x;
    vector<string> v;
    double total_yen =0;
    double xx;
    string vv;
    cin >> N;
    rep(i,N){
        cin >> xx >> vv;
        x.push_back(xx);
        v.push_back(vv);
    }

    rep(i,N){
        if(v[i]=="BTC"){
            total_yen += 380000*x[i];
        }else{
            total_yen += x[i];
        }
    }

    cout << total_yen;
    return 0;
}