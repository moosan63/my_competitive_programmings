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



int main() {
    Int N;
    cin >> N;

    vvi route = vvi(N+1);
    map<int,int> appear_counts;
    vector<pair<int,int>>memory;

    rep(i,N-1){
        Int x,y;
        cin >> x >> y;
        route[x].push_back(y);
        appear_counts[x]+=1;
        appear_counts[y]+=1;
        memory.push_back(make_pair(x,y));
    }

    int max_appear =0;
    rep(i,N+1){
        max_appear = max(appear_counts[i],max_appear);
    }

    cout << max_appear << endl;

    map<int,map<int,int>> ans;
    map<int,int> outer_used;
    queue<int> next;
    next.push(1);
    while(!next.empty()){
        Int now = next.front();
        next.pop();
        int color_num = 1;
        rep(i,route[now].size()){
            Int now_connector = route[now][i];
            if(color_num == outer_used[now]){
                color_num++;
            }
            ans[now][now_connector] = color_num;
            ans[now_connector][now] = color_num;
            outer_used[now_connector] = color_num;

            next.push(now_connector);
            color_num++;
        }
    }

    rep(i,N-1){
        cout << ans[memory[i].first][memory[i].second] << endl;
    }

    return 0;
}