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


int main() {
    vector<vector<Int>> dp;
    Int W,H;
    cin >> W >> H;
    dp = vector<vector<Int>>(W+1,vector<Int>(H+1,0));
    for(int i=0; i<=W; i++){
        dp[i][1] = 1;
    }
    for(int i=0; i<=H; i++){
        dp[1][i] = 1;
    }

    for(int i=2; i<=W; i++){
        for(int j=2; j<=H; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= 1000000007;
        }
    }

    cout << dp[W][H] << endl;
    return 0;
}

