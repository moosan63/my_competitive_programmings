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
#include <math.h>
#define REP(i, b, n) for (Int i = b; i < Int(n); i++)
#define rep(i, n) REP(i, 0, n)
using namespace std;
using Int = long long;
Int inf = 1000000000000000001LL;
using vi = vector<Int>;
using vvi = vector<vi>;
using pii = pair<Int,Int>;
using mapis = unordered_map<Int,string>;
using mapii = unordered_map<Int,Int>;

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

Int LCM(Int a, Int b){
    return a*b/GCD(a,b);
}


int main() {
    Int N, K;
    cin >> N >> K;
    Int count = 0;
    vi A = vi(N);

    rep(i,N){
        cin >> A[i];
    }

    int head = -1;
    int tail = 0;

    Int total =0;
    while(head<N){
        if(total<K){
            head++;
            total += A[head];
            if(head==N){
                break;
            }
        }

        while(total>=K){
            count += (N-head);
            total-= A[tail];
            tail++;
        }
    }

    cout << count << endl;
    return 0;
}