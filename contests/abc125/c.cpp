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

Int gcd(Int a, Int b) {
    if(a < b) return gcd(b, a);
    unsigned r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}

int main() {
    int N;
    cin >> N;
    vector<Int> a = vector<Int>(N);

    for(int i =0; i<N; i++){
        cin >>a[i];
    }

    Int min = inf;
    Int max = 0;
    pair<int,int> min_p;
    pair<int,int> max_p;
    for(int i=0;i<N; i++){
        for(int j = i; j<N; j++){
            if(i==j) continue;
            int g = gcd(a[i],a[j]);
            if(g<min){
                min = g;
                min_p.first = i;
                min_p.second = j;
            }
            if(g>max){
                max = g;
                max_p.first = i;
                max_p.second = j;
            }
        }
    }

    if ( gcd(a[min_p.first], a[max_p.second]) > gcd(a[min_p.second], a[max_p.second])){
        a[min_p.second] = a[max_p.second];
    }else{
        a[min_p.first] = a[max_p.second];
    }

    cout << max << endl;
    return 0;
}

