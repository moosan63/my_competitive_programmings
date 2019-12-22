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
    Int N;
    Int ans = 0;
    cin >> N;
    vi A = vi(N);
    rep(i,N){
        cin >> A[i];
    }

    vvi stack;

    vi zero = vi(1,A[0]);
    stack.push_back(zero);
    REP(i,1,N){
        vi top = stack[stack.size()-1];
        if(A[i]>top[top.size()-1]){
            stack[stack.size()-1].push_back(A[i]);
        }else{
            if(stack.size()>1){
                ans++;
                stack.pop_back();
            }
            top = stack[stack.size()-1];
            if(A[i]>top[top.size()-1]) {
                top.push_back(A[i]);
            }else{
                stack.push_back(vi(1,A[i]));
            }
        }
    }

    ans += stack.size();

    cout << ans << endl;

    return 0;
}