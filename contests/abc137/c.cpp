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


Int combination(Int n, Int r) {
    if(n == 1){return 0;}
    if ( r * 2 > n ) r = n - r;
    uintmax_t dividend = 1;
    uintmax_t divisor  = 1;
    for ( unsigned int i = 1; i <= r; ++i ) {
        dividend *= (n-i+1);
        divisor  *= i;
    }
    return dividend / divisor;
}

int main() {
    Int N;
    cin >> N;
    map<string,int> mp;
    vi memo = vi(N,0);

    set<string> set;
    rep(i,N){
        string s;
        cin>>s;
        std::vector<char> data(s.begin(), s.end());
        sort(data.begin(), data.end());
        std::string sorted(data.begin(), data.end());
        mp[sorted]++;
        set.insert(sorted);
    }

    Int ans =0;
    for(auto itr = set.begin(); itr != set.end(); ++itr) {
        if(memo[mp[*itr]] != 0){
            ans+= memo[mp[*itr]];
        }else{
            Int com = combination(mp[*itr],2);
            ans+=com;
        }

    }



    cout << ans << endl;

    return 0;
}