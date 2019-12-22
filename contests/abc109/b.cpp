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
    Int N,M,X,Y;
    cin >>N>>M>>X>>Y;
    string ans = "War";

    vi x = vi(N+1);
    vi y = vi(M+1);

    x[0] = X;
    y[0] = Y;
    REP(i,1,N+1){
        cin >> x[i];
    }

    REP(i,1,M+1){
        cin >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    if(x[x.size()-1]< y[0]){
        ans = "No War";
    }

    cout<<ans<<endl;
    return 0;
}