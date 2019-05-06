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

string a;

void status_change(int from,int N){
    for(int i=from; i<N; i++){
        if(a[i] == 'd'){
            a[i]='s';
        }else{
            a[i]='d';
        }
    }
}

int main() {
    int N;
    cin >> N;
    int c_f, c_b;
    vi route;
    vi done = vi(N+1, 0);
    cin >> c_f >> c_b;
    cin >> a;
    vi v(N-1);
    iota(v.begin(), v.end(), 1);

    vi min_route;
    Int total_min = 99999999;
    while( next_permutation(v.begin(), v.end()) ){
        Int tmp =0;
        for(auto x: v){
            if (a[x] == 's'){
                if(a[x]>a[x-1]){
                    tmp += c_f;
                }else{
                    tmp += c_b;
                }
            }else{
                tmp += 999;
            }
            status_change(a[x], N);
        }
        if (total_min>tmp){
            min_route = v;
            total_min = tmp;
        }

    }


    cout << N << " ";
    rep(i,N-1){
        cout << min_route[i] << " ";
    }
    cout << N <<endl;
    return 0;
}