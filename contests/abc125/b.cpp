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
    Int X =0;
    Int Y =0;
    cin >> N;

    vector<int> c = vector<int>(N);
    vector<int> v = vector<int>(N);

    for(int i=0; i<N; i++){
        cin >> v[i];
    }
    for(int i=0; i<N; i++){
        cin >> c[i];
    }
    for(int i=0; i<N; i++){
        if(v[i]-c[i]>0){
            X+= v[i];
            Y+= c[i];
        }
    }

    cout << X-Y << endl;
    return 0;
}