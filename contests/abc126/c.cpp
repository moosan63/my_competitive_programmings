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

long double count(Int point, Int goal){
    long double count=0;
    long double pow=1;
    while(point< goal){
        point *= 2;
        count++;
    }
    rep(i,count){
        pow*=2;
    }
    return pow;
}

int main() {
    long double N,K;
    cin >> N >> K;
    vector<long double> a;
    long double ans =0;

    REP(i,1,N+1){
        long double base = (1.0/N);
        long double plus;
        long double pow_count = count(i,K);
        if(pow_count == 0){
            a.push_back(base);
        }else{
            plus = 1/pow_count;
            a.push_back(base*plus);
        }
    }

    rep(i,a.size()){
        ans += a[i];
    }

    cout << setprecision(12) <<ans << endl;

    return 0;
}