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

vi P;
vvi S;
vi K;

Int dfs_bit(vi switches,int move, int up, int now_index, int max_index, int M){
    if(now_index == max_index){
        return 0;
    }

    int flag = 0;
    int ans = 0;
    rep(i,M){
        int tmp_total=0;
        rep(j,K[i]){
            tmp_total += switches[S[i][j]];
        }

        // 合わなかったら立てる
        // そもそもスイッチが1個も押されてないとつかない
        if(tmp_total%2 !=P[i] || tmp_total == 0){
            flag = 1;
        }
    }
    if(flag != 1){
        ans++;
    }


    return ans;
}

int main() {
    Int N,M,ans;
    cin >> N >> M;



    cout << ans << endl;

    return 0;
}