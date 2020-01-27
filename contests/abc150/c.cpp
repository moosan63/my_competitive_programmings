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

int ans =0;

void dfs(string bit, int length,vector<vector<pii>> &answers){
    if(bit.size() == length){
        int tmp_ans = 0;
        int count_shoujiki = 0;
        rep(i,length){
            if(bit[i] =='1'){
                count_shoujiki++;
                bool goal = true;
                rep(j,answers[i].size()){
                    int x = answers[i][j].first;
                    int y = answers[i][j].second;

                    if (ctoi(bit[x]) != y) {goal = false;}
                }

                if(goal){
                    tmp_ans++;
                }
            }
        }
        if(tmp_ans == count_shoujiki){
            ans = max(ans,count_shoujiki);
        }

        return;
    }
    dfs(bit+"1", length, answers);
    dfs(bit+"0", length, answers);
    return ;
}

int main() {
    Int N;
    Int Ans;

    cin >> N;

    vi p = vi(N);
    vi q = vi(N);

    rep(i,N){
        cin >> p[i];
    }

    rep(i,N){
        cin >> q[i];
    }

    Int p_i=-1, q_i=-1;

    vector<int> nums(N);
    iota(nums.begin(), nums.end(), 1);

    Int index = 1;
    do {
        bool p_match=true;
        rep(i,N){
            if(p_i != -1){continue;}
            if(p[i]!=nums[i]){
                p_match = false;
            }
        }

        bool q_match = true;
        rep(i,N){
            if(q_i != -1){continue;}
            if(q[i]!=nums[i]){
                q_match = false;
            }
        }

        if(p_match&&p_i ==-1){
            p_i = index;
        }

        if(q_match&&q_i == -1){
            q_i = index;
        }
        index++;

    } while (next_permutation(nums.begin(), nums.end()));


    cout << abs(p_i-q_i) << endl;



    return 0;
}