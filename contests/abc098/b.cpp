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
    string S;
    cin >> N >> S;


    int ans =0;

    for(int i=1; i< N; i++){
        unordered_map<char, int> kind;
        for(int ii=0; ii<i; ii++){
            kind[S[ii]] = 1;
        }
        for(int k=N; k>=i;k--){
            if(kind[S[k]]>0){
                kind[S[k]] += 1;
            }else{
                kind[S[k]] = 0;
            }
        }

        int tmp =0;
        for(auto itr = kind.begin(); itr != kind.end(); ++itr) {
            if(itr->second > 1){
                tmp++;
            }
        }
        ans = max(ans,tmp);
    }

    cout << ans << endl;
    return 0;
}