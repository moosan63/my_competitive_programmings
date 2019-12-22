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
#include <cmath>
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

Int modinv(Int a, Int m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

Int binary_search_index(Int Y, vi &q){
    int left = 0, right = q.size() - 1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (q[mid] == Y) return mid;
        else if (q[mid] > Y) right = mid - 1;
        else if (q[mid] < Y) left = mid + 1;
    }
    return -1;
}

bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int root_sum(int target, vi &parents, vi &nodes_value, vi &memo, int sum){
    if(memo[target] != -1){
        sum += memo[target];
        return sum;
    }
    if (parents[target] == target){
        sum+=nodes_value[target];
        return sum;
    }else{
        sum+=nodes_value[target];
        return root_sum(parents[target],parents, nodes_value, memo, sum);
    }
}

// memoには数え上げた素数を入れていく
bool is_prime(Int n, map<Int,Int> &memo){
    if(memo[n] == 1){
        return false;
    }else if(memo[n] == 2){
        return true;
    }

    bool prime = true;
    for(Int i =2; i<=sqrt(n)+2; i++){
        if(memo[i]==2 && n%i==0){
            prime = false;
        }
    }
    if(prime){
        memo[n] = 2;
    }else{
        memo[n] = 1;
    }

    return prime;
}

vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(10, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 10; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'0'] = i;
    }
    return res;
}
const int MOD = 1000000007;

// mod 1000000007 の世界で a += b する関数
void add(long long &a, long long b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
    Int n;
    string S;
    cin >> n >> S;

    vector<vector<int> > next = calcNext(S);

    int res = next[1]['2'];

    cout << res << endl;


    return 0;
}