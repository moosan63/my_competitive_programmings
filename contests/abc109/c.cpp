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
    Int N,X;
    cin >> N >> X;
    vi x = vi(N);
    rep(i,N){
        cin >> x[i];
    }
    Int ans =0;

    if(x.size() == 1){
        ans = abs(X-x[0]);

    }else if (x.size() == 2){
        ans = GCD(abs(X-x[0]),abs(X-x[1]));
    }else{
        ans = GCD(abs(X-x[0]),abs(X-x[1]));
        REP(i,2,N){
            ans = GCD(ans,abs(X-x[i]));
        }
    }


    cout << ans << endl;

    return 0;
}