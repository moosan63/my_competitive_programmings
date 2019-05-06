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

int main() {
    int N;
    int H[20];
    int hmax =0;
    int view_count = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> H[i];
    }

    for(int i =0;i<N; i++){
        if(hmax <= H[i]){
            hmax = H[i];
            view_count++;
        }
    }
    cout << view_count << endl;
    return 0;
}