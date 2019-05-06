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
    int N;
    cin >> N;
    vector<int> a(N);


    for(int i=0; i<N; i++){
        cin >> a[i];
    }

    int head =1;
    int ans=0;
    for (int tail = 0; tail < N; tail++) {
        while(head<N && a[head]>a[head-1]){
            head++;
        }

        ans += head-tail;

        if (tail+1 == head) {
            head++;
        }
    }

    cout << ans << endl;
    return 0;
}