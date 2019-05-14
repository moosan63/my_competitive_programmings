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

int dfs(Int number, string target, int count,bool three, bool five, bool seven){
    if(stoll(target) > number){
        return 0;
    }

    if(target == "0"){
        target = "";
    }

    int ans = 0;
    if(three && five&& seven){
        ans= 1;
    }
    ans += dfs(number, target+"3", count+1, true,five,seven);
    ans += dfs(number, target+"5", count+1,three,true,seven);
    ans += dfs(number, target+"7",count+1, three,five,true);

    return  ans;
}

int main() {
    Int N;
    cin >> N;
    Int ans;

    if(N<357){
        ans =0;
    }else{
        string start ="0";
        ans = dfs(N, start, 0, false,false,false);
    }

    cout << ans << endl;
    return 0;
}