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
Int Vmax = 10000;

int main() {
    int N, W;
    Int thisVmax =0;
    cin >> N >> W;

    vector<vector<Int>> dp = vector<vector<Int>>(N+10,vector<Int>(Vmax+10,0));
    vector<Int> weights = vector<Int>(N);
    vector<Int> values = vector<Int>(N);

    for(int i=0; i<N; i++){
        cin >> weights[i] >> values[i];
        thisVmax += values[i];
    }

    for(int i =0;i<Vmax; i++){
        dp[0][i] = inf;
    }

    for(int i = 0; i<N; i++){
        for(int v=0; v<=Vmax; v++){
            if(v >= values[i]){
                dp[i+1][v] =  min(
                        dp[i][v-values[i]]+weights[i],
                        dp[i][v]
                );
            }else{
                dp[i+1][v] = weights[i];

            }

        }
    }
    int ans =0;
    for(int i=thisVmax; i>0; i--){
        if(dp[N][i]-1<= W){
            ans = dp[N][i];
            break;
        }
    }

    cout <<  ans << endl;
    return 0;
}

