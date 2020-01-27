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
int binary_search_index(Int Y, vi &q){
    int left = 0, right = q.size() - 1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (q[mid] == Y) return mid;
        else if (q[mid] > Y) right = mid - 1;
        else if (q[mid] < Y) left = mid + 1;
    }
    return -1;
}


Int combination(Int n, Int r) {
    if(n == 1){return 0;}
    if ( r * 2 > n ) r = n - r;
    uintmax_t dividend = 1;
    uintmax_t divisor  = 1;
    for ( unsigned int i = 1; i <= r; ++i ) {
        dividend *= (n-i+1);
        divisor  *= i;
    }
    return dividend / divisor;
}

unsigned GetDigit(Int num){
    return std::to_string(num).length();
}
int ctoi(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    return 0;
}



int main() {
    Int N;
    Int ans = 1;
    cin >> N;

    mapii counts;

    rep(i,N){
        Int a;
        cin >> a;
        counts[a]++;
    }

    Int mod = 1000000000+7;



    if(N%2==1){
        if(counts[0]!=1){
            cout << 0 << endl;
            return 0;
        }
        Int tmp = 0;
        while(tmp<N){
            if(tmp==0){
                if (counts[tmp]!=1){
                    cout << 0 << endl;
                    return 0;
                }
            }else{
                if(counts[tmp]!=2){
                    cout << 0 << endl;
                    return 0;
                }
                ans*=2;
                ans%=mod;
            }
            tmp+= 2;
        }

        cout << ans << endl;

    }else{
        Int tmp = 1;
        while(tmp<N){
            if(counts[tmp]!=2){
                cout << 0 << endl;
                return 0;
            }

            ans*=2;
            ans%=mod;
            tmp += 2;
        }

        cout << (ans)%mod << endl;
    }



    return 0;
}