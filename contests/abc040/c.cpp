//
// Created by 村上怜 on 2019-04-19.
//

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
Int inf = 1000000000000000001LL;
vector<int> a;
int N;

int main() {
    cin >> N;

    vector<int> dp;

    for(int i =0;i<N;i++){
        int n;
        cin >> n;
        a.push_back(n);
    }

    int n = N-1;

    dp = vector<int>(N,0);

    dp[0] = 0;
    dp[1] = abs(a[0]-a[1]);
    dp[2] = abs(a[0]-a[2]);
    for(int i = 3; i<N; i++){
        dp[i] = min(
                    dp[i-1] + abs(a[i-1]-a[i]),
                    dp[i-2] + abs(a[i-2]-a[i])
                );
    }


    cout << dp[N-1] << endl;
    return 0;
}