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
    Int N;
    cin >> N;

    vector<Int> a = vector<Int>(N);
    for(Int i=0; i < N; i++){
        cin >>a[i];
    }

    Int ans = 0;

    int head =0;
    for(int tail=0; tail < N; tail++){
        while(head<N && tail<N){
            Int xor_sum = a[tail];
            Int sum = a[tail];

            if(head==tail){
                ans++;
                head++;
            }

            // 上の演算の結果headが配列超えたら終わり
            if(head >= N) {
                break;
            }

            for(int i=head; tail<i; i--){
                xor_sum = xor_sum^a[i];
                sum += a[i];

            }
            if(xor_sum == sum){
                ans += head-tail+1;
                head++;
            }else{
                break;
            }
        }
    }

    cout << ans << endl;
    return 0;
}