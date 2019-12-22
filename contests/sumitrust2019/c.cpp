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

Int dfs(int count, int limit, int this_total, int select, int target){
    if(count >limit){
        return 0;
    }

    int total = this_total + select;

    if (total > target){
        return 0;
    }

    if (total==target) {
        return 1;
    }

    int onigiri = dfs(count+1, limit, total, 0, target);
    int sand = dfs(count+1, limit, total, 1, target);
    int cook = dfs(count+1, limit, total, 2, target);
    int cake = dfs(count+1, limit, total, 3, target);
    int ame = dfs(count+1, limit, total, 4, target);
    int pc = dfs(count+1, limit, total, 5, target);

    return onigiri + sand + cook + cake + ame + pc;
}

int main() {
    int X;
    cin >> X;

    int divided100 = X/100;
    int amari = X%100;

    if (amari == 0){
        cout << 1<<endl;
        return 0;
    }

//    int onigiri = dfs(0, divided100, 0, 0,amari);
//    int sand = dfs(0, divided100, 0, 1,amari);
//    int cook = dfs(0, divided100, 0, 2,amari);
//    int cake = dfs(0, divided100, 0, 3,amari);
//    int ame = dfs(0, divided100, 0, 4,amari);
//    int pc = dfs(0, divided100, 0, 5,amari);
//
//    int ans = onigiri+ sand + cook + cake + ame + pc;

    int count5 = amari/5;
    int five_amari = amari%5;

    if(five_amari == 0 && count5<=divided100){
        cout << 1<<endl;
        return 0;
    }

    int count4 = five_amari/4;
    int four_amari = five_amari%4;

    if(four_amari == 0 && count5+count4<=divided100){
        cout << 1<<endl;
        return 0;
    }

    int count3 = four_amari/3;
    int three_amari = four_amari%3;

    if(three_amari == 0 && count5+count4+count3<=divided100){
        cout << 1<<endl;
        return 0;
    }

    int count2 = three_amari/2;
    int two_amari = three_amari%2;

    if(two_amari == 0 && count5+count4+count3+count2<=divided100){
        cout << 1<<endl;
        return 0;
    }

    int count1 = two_amari/1;
    int one_amari = two_amari%1;

    if(one_amari == 0 && count5+count4+count3+count2+count1<=divided100){
        cout << 1<<endl;
        return 0;
    }




    cout << 0<<endl;




    return 0;
}