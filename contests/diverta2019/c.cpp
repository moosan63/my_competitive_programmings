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

int main() {
    Int N;
    vector<string> S;
    Int firstB =0;
    Int lastA =0;
    Int both =0;
    cin >> N;
    Int ans=0;

    rep(i,N){
        string s;
        cin >> s;
        rep(j,s.size()-1){
            if(s[j]=='A' && s[j+1] == 'B'){
                ans++;
            }
        }
        if (s[0] == 'B' && s[s.size()-1] == 'A'){
            both++;
        }else{
            if(s[0] == 'B'){
                firstB++;
            }
            if(s[s.size()-1] == 'A'){
                lastA++;
            }
        }
    }


    ans+= min(firstB,lastA);
    if(both >0){
        if(firstB != lastA){
            ans+= both-1;
            ans++;
        }else{
            ans += both-1;
        }
    }

    cout << ans << endl;
    return 0;
}