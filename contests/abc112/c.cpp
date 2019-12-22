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
    Int N;
    cin >>N;
    vi x = vi(N);
    vi y = vi(N);
    vi h = vi(N);

    int xx;
    int yy;
    int hh;

    rep(i,N){
        cin >> x[i];
        cin >> y[i];
        cin >> h[i];
        if (h[i]>=1){
            xx = x[i];
            yy = y[i];
            hh = h[i];
        }
    }

    if (N==1){
        cout << x[0] << " " << y[0] << " " << h[0] << endl;
        return 0;
    }

    vvi cands = vvi(101,vi(101,0));
    rep(i,101){
        rep(j,101){
            cands[i][j] = max(abs(i-xx)+abs(j-yy)+hh,0LL);
        }
    }

    Int H = -1;
    int X = -1000;
    int Y = -1000;
    bool flag;
    rep(i,101){
        rep(j,101){
            flag = true;
            Int tmp_h = cands[i][j];
            rep(k,N){
                Int ans_tmp = max(tmp_h - abs(i-x[k])-abs(j-y[k]),0LL);
                if(h[k] != ans_tmp){
                    flag = false;
                }
            }
            if(flag){
                X=i;
                Y=j;
                H=max(cands[i][j],0LL);
            }
        }
    }

    cout << X << " " << Y << " " << H << endl;


    return 0;
}