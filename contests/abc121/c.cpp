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
using pi = pair<Int,Int>;

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
    Int N,M, ans;
    cin >> N >> M;
    ans = 0;

    priority_queue<pi,vector<pi>,greater<>> pq;
    int count = 0;
    rep(i,N){
        Int A;
        cin >> A;
        Int B;
        cin >> B;
        pair<Int,Int> p;
        p.first = A;
        p.second = B;
        pq.push(p);
    }

    rep(i,N){
        pair<Int,Int> p= pq.top();
        pq.pop();
        ans += p.first*p.second;
        count += p.second;
        if(count>M){
            ans -= (count-M)*p.first;
            break;
        }
    }



    cout << ans;
    return 0;
}