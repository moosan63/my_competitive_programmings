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

int main() {
    Int N,M;
    cin >>N>>M;
    vi P = vi(M);
    vi Y = vi(M);
    rep(i,M){
        cin >> P[i];
        cin >> Y[i];
    }

    map<Int,vi> mp;
    rep(i,M){
        mp[P[i]].push_back(Y[i]);
    }

    rep(i,N+1){
        sort(mp[i].begin(),mp[i].end());
    }

    rep(i,M){
        stringstream ans;
        Int yi = binary_search_index(Y[i],mp[P[i]])+1;
        ans << std::setw(6) << std::setfill('0') << P[i];
        ans << std::setw(6) << std::setfill('0') << yi;
        cout << ans.str() << endl;
    }


    return 0;
}