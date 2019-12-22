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
using mapis = unordered_map<Int,string>;
using mapii = unordered_map<Int,Int>;
using pii = pair<Int,Int>;

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
int binary_search_index(Int Y, vi &q){
    int left = 0, right = q.size() - 1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (q[mid] == Y) return mid;
        else if (q[mid] > Y) right = mid - 1;
        else if (q[mid] < Y) left = mid + 1;
    }
    return -1;
}


Int combination(Int n, Int r) {
    if(n == 1){return 0;}
    if ( r * 2 > n ) r = n - r;
    uintmax_t dividend = 1;
    uintmax_t divisor  = 1;
    for ( unsigned int i = 1; i <= r; ++i ) {
        dividend *= (n-i+1);
        divisor  *= i;
    }
    return dividend / divisor;
}

int main() {
    Int N;
    cin >> N;
    vector<double> v = vector<double>(N);

    rep(i,N){
        cin>>v[i];
    }

    double ans =0;

    sort(v.begin(),v.end());

    double pre = (v[0]+v[1])/2;

    if(N==2){
        cout << pre << endl;
        return 0;
    }

    REP(i,2,N){
      ans = (pre+v[i])/2;
      pre=(pre+v[i])/2;
    }

    cout << ans << endl;

    return 0;
}