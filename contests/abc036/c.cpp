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
    vector<Int> sa = vector<Int>(N);
    unordered_map<Int,Int> indexed_a;
    for(Int i=0; i<N; i++){
        cin >> a[i];
        sa[i] = a[i];
    }

    sort(sa.begin(),sa.end());

    Int now =1;
    indexed_a[sa[0]] = 0;
    for(Int i=1; i<N; i++){
        if(sa[i]>sa[i-1]){
            indexed_a[sa[i]] = now;
            now++;
        }
    }

    for(Int i=0;i<N; i++){
        cout << indexed_a[a[i]] << endl;
    }

    return 0;
}