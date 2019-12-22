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
    vector<int> parents = vector<int>(N+1);

    REP(i,1,N){
        int B;
        cin >> B;
        parents[i+1]=B;
    }

    vector<vector<int>> group(N+2,vector<int>(1,-1));

    for(int i = N+1; i>1; i--){
        if(group[i].size() == 1){
            group[parents[i]].push_back(1);
        }else{
            vector<int> sorted = group[i];
            sort(sorted.begin(),sorted.end());
            group[parents[i]].push_back( sorted[1] + sorted[sorted.size()-1] +1);
        }
    }


    sort(group[1].begin(),group[1].end());
    Int ans = group[1][1] + group[1][group[1].size()-1] +1;

    cout << ans << endl;

    return 0;

//    Int N;
//    cin >> N;
//    vi parents = vi(N+1);
//
//    REP(i,1,N){
//        int B;
//        cin >> B;
//        parents[i+1]=B;
//    }
//
//    vi maxs = vi(N+1,-1);
//    vi mins = vi(N+1,inf);
//
//    for(int i = N; i>0; i--){
//        if(maxs[i] == -1 || mins[i] == inf){
//            if(maxs[parents[i]]<1){
//                maxs[parents[i]] = 1;
//            }
//            if(mins[parents[N-i]]>1){
//                mins[parents[i]] = 1;
//            }
//        }else{
//            Int now = maxs[i]+ mins[i] +1;
//            if(now>maxs[parents[i]]){
//                maxs[parents[i]] = now;
//            }
//            if(now<mins[parents[N-i]]){
//                mins[parents[i]] = now;
//            }
//        }
//    }
//
//    if(maxs[1]==-1){
//        maxs[1]=mins[1];
//    }
//
//    if(mins[1]==inf){
//        mins[1]=maxs[1];
//    }
//
//    cout << maxs[1]+mins[1]+1 << endl;
//
//    return 0;
}