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
    int N,M;

    cin >> N >>M;
    vvi A = vvi(N);
    vi K;
    int ans =0;
    unordered_map<int, int> mp;
    rep(i,N){
        int k;
        cin >> k;
        rep(j,k){
            int a;
            cin >> a;
            mp[a]++;
        }
    }

    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
                  if(itr->second == N){
                    ans++;
                  }
    }


    cout << ans;
    return 0;
}