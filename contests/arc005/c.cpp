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

vi cost;
vvi cost_to;
vi done;

int dijkstra1n(int start, int goal, int N){
    Int min, target;
    target = -1;
    cost[start] = 0;
    while(true){
        int all=0;
        min = inf;
        for(int i=1; i<=N; i++){
            if(done[i] ==0 && min > cost[i]){
                min = cost[i];
                target = i;
            }
            all += done[i];
        }

        if (all == N) {
            return cost[goal];
        }

        for(int i=1; i<=N; i++){
            if(cost[i] > cost[target]+cost_to[target][i]) {
                cost[i] = cost[target]+cost_to[target][i];
            }
        }
        done[target] = 1;
    }
}


int main() {
    Int H,W;
    cin >> H >> W;



    rep(i,H*W){
        cin >> ;
    }


    cout << ans << endl;

    return 0;
}