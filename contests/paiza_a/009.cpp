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
    int H,W;
    cin >> H >> W;
    int ans =0;
    vector<string> map = vector<string>(H);
    rep(i,H){
        cin >> map[H-1-i];
    }

    int now_h =H-1;
    int now_w =0;
    char now_dir = 'r';
    while((now_h<H && now_w <W)) {

        if (map[now_h][now_w] == '_') {
            ans++;
            if (now_dir == 'r') {
                now_w += 1;
            } else if(now_dir == 'l') {
                now_w -= 1;
            } else if(now_dir == 't') {
                now_h += 1;
            } else if(now_dir == 'b') {
                now_h -= 1;
            }
        } else if (map[now_h][now_w] == '/') {
            ans++;
            if(now_dir=='r'){
                now_dir = 't';
                now_h += 1;
            }else if(now_dir == 'l'){
                now_dir = 'b';
                now_h -= 1;
            }else if(now_dir == 'b'){
                now_dir = 'l';
                now_w -= 1;
            }else if(now_dir == 't'){
                now_dir = 'r';
                now_w += 1;
            }
        } else if (map[now_h][now_w] == '\\') {
            ans++;
            if(now_dir=='r'){
                now_dir = 'b';
                now_h -= 1;
            }else if(now_dir == 'l'){
                now_dir = 't';
                now_h += 1;
            }else if(now_dir == 'b'){
                now_dir = 'r';
                now_w += 1;
            }else if(now_dir == 't'){
                now_dir = 'l';
                now_w -= 1;
            }
        }
        if(now_h == -1 || now_w ==-1){
            break;
        }
    }
    cout << ans <<endl;
    return 0;
}