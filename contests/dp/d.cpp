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
int main() {
    int N, W;
    cin >> N >> W;

    vector<vector<Int>> dp = vector<vector<Int>>(N+10,vector<Int>(W+10,0));
    vector<Int> weights = vector<Int>(N);
    vector<Int> values = vector<Int>(N);

    for(int i=0; i<N; i++){
        cin >> weights[i] >> values[i];
    }

    for(int i =0;i<W; i++){
        dp[0][W] = 0;
    }

    for(int i = 0; i<N; ++i){
        for(int w=0; w<=W; ++w){
            if(w >= weights[i]){
                dp[i+1][w] =  max(
                        dp[i][w-weights[i]]+values[i],
                        dp[i][w]
                );
            }else{
                dp[i+1][w] = dp[i][w];

            }

        }
    }


    cout <<  dp[N][W] << endl;
    return 0;
}