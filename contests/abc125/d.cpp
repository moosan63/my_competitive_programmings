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
    int N;
    cin >> N;
    vector<Int> a = vector<Int>(N);

    for(int i =0; i<N; i++){
        cin >> a[i];
    }


    cout << ans << endl;
    return 0;
}