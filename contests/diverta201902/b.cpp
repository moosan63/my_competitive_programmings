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
#define REP(i, b, n) for (Int i = b; i < Int(n); i++)
#define rep(i, n) REP(i, 0, n)
using namespace std;
using Int = long long;
Int inf = 1000000000000000001LL;
using vi = vector<Int>;
using vvi = vector<vi>;
using mapis = unordered_map<Int,string>;
using mapii = unordered_map<Int,Int>;
using pii = pair<Int,Int>;

Int GCD(Int a, Int b){
    if(b==0) return a;
    if(a < b) return GCD(b, a);
    unsigned r;
    while ((r=a%b)) {
        a = b;
        b = r;
    }
    return b;
}
Int printX(Int r, Int D, Int X, int count){
    if(count == 10){
        return 0;
    }
    Int nextX = r*X - D;
    cout<< nextX <<endl;
    printX(r,D,nextX,count+1);

}

bool pairCompare(const pair<Int,Int>& firstElof, const pair<Int,Int>& secondElof)
{
    return firstElof.second < secondElof.second;
}

int main() {
    int N;
    cin >> N;
    vector<pair<Int,Int>> XY = vector<pair<Int,Int>>(N);

    rep(i,N){
        Int a, b;
        cin >>a >> b;
        XY[i].first = a;
        XY[i].second = b;
    }

    map<string,int> xmp;
    int key_max =0;

    // 差分の組み合わせを全部mapにいれて数える
    rep(i,N){
        rep(j,N){
            if(i==j) {
                continue;
            }
            Int p, q;
            p = XY[i].first - XY[j].first;
            q = XY[i].second - XY[j].second;
            string diff;
            diff = to_string(p)+","+to_string(q);
            xmp[diff]++;
        }
    }

    // 出てきた中で一番大きい差分をp,qとする
    for(auto itr = xmp.begin(); itr != xmp.end(); itr++){
        key_max = max(key_max, xmp[itr->first]);
    }


    // 辺の数 - 一番コスト低く取れるp,qの組み合わせの数
    cout << N-key_max << endl;
    return 0;
}
