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
int main() {
    Int H,W;
    vvi done;
    vector<vector<char>> A;

    cin >> H >> W;
    A = vector<vector<char>>(H,vector<char>(W,0));
    done = vvi(H,vi(W,-1));
    rep(i,H){
        rep(j, W){
            cin>> A[i][j];
        }
    }

    Int ans = 0;
    queue<pii> next_points;
    rep(i,H){
        rep(j, W){
            if(A[i][j] == '#'){
                next_points.push(pii(i,j));
                done[i][j] = 0;
            }
        }
    }

    while(!next_points.empty()){
        pii now = next_points.front();
        next_points.pop();

        if(now.first+1 != H){
            if(done[now.first+1][now.second] == -1){
                done[now.first+1][now.second] = done[now.first][now.second]+1;
                ans = max(ans,done[now.first+1][now.second]);
                next_points.push(pii(now.first+1,now.second));
            }
        }

        if(now.second+1 != W ){
            if(done[now.first][now.second+1] == -1){
                done[now.first][now.second+1] = done[now.first][now.second]+1;
                ans = max(ans,done[now.first][now.second+1]);
                next_points.push(pii(now.first,now.second+1));
            }
        }

        if(now.first-1 >=0){
            if(done[now.first-1][now.second] == -1){
                done[now.first-1][now.second] = done[now.first][now.second]+1;
                ans = max(ans,done[now.first-1][now.second]);
                next_points.push(pii(now.first-1,now.second));
            }

        }
        if(now.second-1 >=0){
            if(done[now.first][now.second-1] == -1){
                done[now.first][now.second-1] = done[now.first][now.second]+1;
                ans = max(ans,done[now.first][now.second-1]);
                next_points.push(pii(now.first,now.second-1));
            }
        }

    }


    cout << ans <<endl;
    return 0;
}