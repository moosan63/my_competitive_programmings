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


bool is_prime(int n, map<int,int> &memo){
    if(memo[n] == 1){
        return false;
    }else if(memo[n] == 2){
        return true;
    }

    bool prime = true;
    double sqrt_n = sqrt(double(n));
    for(int i =2; i<=max(2,int(sqrt_n)); i++){
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

int main() {
    Int N;
    cin >> N;

    map<int,int> memo;
    memo[0]=1;
    memo[1]=1;
    memo[2]=2;
    vi answers;

    REP(i,2,55555){
        if(is_prime(i,memo) && i%5 == 1){
            answers.push_back(i);
        }

        if(answers.size() == N){
            break;
        }
    }

    rep(i,answers.size()){
        cout << answers[i] << " ";
    }
    cout << endl;


    return 0;
}