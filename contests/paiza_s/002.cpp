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

int start_i, start_j;
int goal_i, goal_j;
int N,M;
vvi done_a;
vvi done_b;
vvi done_c;
vvi done_d;
vector<vector<char>> nm;

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

int dfs(int source_i, int source_j, int i, int j,Int cost){
    if(i == goal_i && j == goal_j){
        return cost;
    }
    if(nm[i][j]=='1'){
        return 99999999;
    }

    int a=999999999,b=999999999,c=999999999,d=999999999;
    if(i+1 != source_i && i<M-1 && done_a[i+1][j] != 1){
        done_a[i+1][j] = 1;
        a = dfs(i,j,i+1,j,cost+1);
    }
    if(i-1 != source_i && i>0 && done_b[i-1][j] != 1){
        done_b[i-1][j] = 1;
        b = dfs(i,j,i-1,j,cost+1);
    }
    if(j+1 != source_j && j<N-1 && done_c[i][j+1] != 1){
        done_c[i][j+1] = 1;
        c = dfs(i,j,i,j+1,cost+1);
    }
    if(j-1 != source_j && j>0 && done_d[i][j-1] != 1){
        done_d[i][j-1] = 1;
        d = dfs(i,j,i,j-1,cost+1);
    }

    return min(a,(min(b,min(c,d))));
}

int main() {
    Int ans;
    cin >> N >> M;
    nm = vector<vector<char>>(M,vector<char>(N,'0'));
    done_a = vvi(M,vi(N,0));
    done_b = vvi(M,vi(N,0));
    done_c = vvi(M,vi(N,0));
    done_d = vvi(M,vi(N,0));
    rep(i,M){
        rep(j,N){
            cin >> nm[i][j];

            if(nm[i][j] == 's'){
                start_i = i;
                start_j = j;
            }
            if(nm[i][j] == 'g'){
                goal_i = i;
                goal_j = j;
            }
        }
    }
    ans = dfs(start_i,start_j,start_i,start_j,0);

    if(ans != 99999999){
        cout << ans;
    }else{
        cout << "Fail";
    }

    return 0;
}

