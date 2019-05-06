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
using namespace std;
using Int = long long;
Int inf = 100000000000000001LL;
int main() {
    int N;
    cin >> N;
    vector<Int> h = vector<Int>(N+1);
    for(int i=1;i<=N;i++){
        cin>>h[i];
    }
    vector<Int> dp = vector<Int>(N+1, inf);
    dp[1] = 0;

    for(int i=1; i<=N+1; i++){
        if(i+1<=N){
            dp[i+1] = min(dp[i+1],abs(h[i+1] - h[i]) + dp[i]);
        }
        if(i+2<=N){
            dp[i+2] = min(dp[i+2],abs(h[i+2] - h[i]) + dp[i]);
        }

    }

    cout << dp[N] << endl;
    return 0;
}