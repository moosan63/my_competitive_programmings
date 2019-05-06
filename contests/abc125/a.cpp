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
    int A, B, T;
    cin >> A >> B >> T;
    int ans =0;
    int time = A;

        while(time <= T+0.5){
            ans += B;
            time += A;
        }
    cout << ans << endl;
    return 0;
}