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

vector<string> burger_memo;
void make_burgar(int n, int goal){
    if(n==1){
        return;
    }

    string this_level_burger;
    this_level_burger = "B"+burger_memo[n-1]+"P"+burger_memo[n-1]+"B";;
    burger_memo[n] = this_level_burger;


    if(n==goal){
        return;
    }else{
        make_burgar(n+1,goal);
    }
}

int main() {
    Int N,X;
    cin >> N >> X;
    Int ans = 0;

    string level1 = "BPPPB";
    burger_memo = vector<string>(51,"");
    burger_memo[1] = level1;
    if(N!=1){
        make_burgar(2,N);
    }
    string target = burger_memo[N];
    rep(i,X){
        if(target[i]=='P'){
            ans++;
        }
    }

    cout << ans;
    return 0;
}