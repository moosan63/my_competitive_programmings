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
using mapis = unordered_map<Int,string>;
using mapii = unordered_map<Int,Int>;

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

Int LCM(Int a, Int b){
    return a*b/GCD(a,b);
}



int main() {
    Int N,A,B,C,D;
    string S;
    cin >> N >> A >> B >> C >> D;
    cin >> S;
    string ans;

    if(C<D){ // [A B . # C D] や [A . # C . B # D] みたいなとき
        ans = "Yes";
        // それぞれ進行方向に # # がある時点で駄目、それ以外はなんとかなる
        REP(i,A-1,C-1){
            if(S[i] == '#' && S[i+1]=='#'){
                ans = "No";
                break;
            }
        }
        REP(i,B-1,D-1){
            if(S[i] == '#' && S[i+1]=='#'){
                ans = "No";
                break;
            }
        }
    }else{ // A B . # D C みたいなとき
        ans = "No";
        REP(i,B-1,D-1){
            // とりあえずAからCの間でどっかに[. . .]があれば前後ひっくり返してC<Dの条件と同等にできる
            if(S[i-1]=='.' && S[i]=='.' && S[i+1] == '.'){
                ans = "Yes";
            }
        }
        // まあどっちにしろ途中に岩が2連続あるなら駄目
        REP(i,A-1,C-1){
            if(S[i] == '#' && S[i+1]=='#'){
                ans = "No";
                break;
            }
        }
        REP(i,B-1,D-1){
            if(S[i] == '#' && S[i+1]=='#'){
                ans = "No";
                break;
            }
        }
    }


    cout << ans << endl;
    return 0;
}