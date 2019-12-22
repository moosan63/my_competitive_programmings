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

int main() {
    string s;

    cin >> s;

    Int tail = 0;
    Int head = 1;
    int r_count =0;

    vi ans = vi(s.size());
    while(head<s.size()){
        if(s[tail]=='R'){
            if(s[head]=='R'){
                ans[head-1]=0;
                head++;
            }else{
                r_count = head-tail;
                tail = head;
                head++;
            }
        }else{
            if(s[head]=='L'){
                ans[tail]++;
                ans[head] = 0;
                head++;
            }else{
                // 両方偶数のときは分配される
                if(r_count%2==0 && (head-tail)%2==0){
                    ans[tail-1]= (r_count+(head-tail))/2;
                    ans[tail]= (r_count+(head-tail))/2;
                // 奇数と偶数のときは奇数が奪う
                }else if(r_count%2==0 && (head-tail)%2!=0){
                    ans[tail] = (r_count+(head-tail)+1)/2;
                    ans[tail-1] = ((r_count+(head-tail)+1)/2) -1;
                }else if(r_count%2!=0 && (head-tail)%2==0){
                    ans[tail-1] = (r_count+(head-tail)+1)/2;
                    ans[tail] = ((r_count+(head-tail)+1)/2) -1;
                // 両方奇数も分配？
                }else if (r_count%2!=0 && (head-tail)%2!=0){
                    ans[tail-1] = (r_count+(head-tail)+1)/2;
                    ans[tail] = (r_count+(head-tail)+1)/2;
                }

                r_count = 0;
                tail = head;
                head = head+1;
            }
        }
    }

    // ケツの処理
    if(r_count%2==0 && (head-tail)%2==0){
        ans[tail-1]= (r_count+(head-tail))/2;
        ans[tail]= (r_count+(head-tail))/2;
        // 奇数と偶数のときは奇数が奪う
    }else if(r_count%2==0 && (head-tail)%2!=0){
        ans[tail] = (r_count+(head-tail)+1)/2;
        ans[tail-1] = ((r_count+(head-tail)+1)/2) -1;
    }else if(r_count%2!=0 && (head-tail)%2==0){
        ans[tail-1] = (r_count+(head-tail)+1)/2;
        ans[tail] = ((r_count+(head-tail)+1)/2) -1;
        // 両方奇数も分配？
    }else if (r_count%2!=0 && (head-tail)%2!=0){
        ans[tail-1] = (r_count+(head-tail)+1)/2;
        ans[tail] = (r_count+(head-tail)+1)/2;
    }


    rep(i,s.size()){
        cout << ans[i] << " ";
    }

    cout << endl;


    return 0;
}