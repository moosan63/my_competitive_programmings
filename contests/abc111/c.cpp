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

int main() {
    Int N;
    cin >>N;
    vi v = vi(N);
    rep(i,N){
        cin >> v[i];
    }
    map<Int,Int> v_odd;
    map<Int,Int> v_even;

    pair<Int,Int> v_odd_max = pair<Int,Int>(-1,0);
    pair<Int,Int> v_even_max = pair<Int,Int>(-1,0);
    pair<Int,Int> v_odd_max2 = pair<Int,Int>(-1,0);
    pair<Int,Int> v_even_max2 = pair<Int,Int>(-1,0);

    // 奇数の数え上げ、最頻値が同数のがあればかぶりのときのために保存する
    for(Int i =0; i<N; i+=2){
        v_even[v[i]]++;
        if(v_even_max.second < v_even[v[i]]){
            v_even_max.first = v[i];
            v_even_max.second = v_even[v[i]];
        }else if (v_even_max2.second < v_even[v[i]]){
            v_even_max2.first = v[i];
            v_even_max2.second = v_even[v[i]];
        }
    }

    // 偶数の数え上げ、最頻値が同数のがあればかぶりのときのために保存する
    for(Int i =1; i<N; i+=2){
        v_odd[v[i]]++;
        if(v_odd_max.second < v_odd[v[i]]){
            v_odd_max.first = v[i];
            v_odd_max.second = v_odd[v[i]];
        }else if (v_odd_max2.second < v_odd[v[i]]){
            v_odd_max2.first = v[i];
            v_odd_max2.second = v_odd[v[i]];
        }
    }

    Int ans =0;


    // 奇数と偶数の、それぞれ1つの最頻値が同じだったら(1,1,1,1,2,2,2,2)みたいな数列
    if(v_odd_max.first == v_even_max.first){
        Int tmp_ans1 = inf;
        Int tmp_ans2 = inf;
        // 奇数に2番目の最頻値があるとき, その最頻値で書き換え
        if(v_odd_max2.first != -1){
            int tmp =0;
            for (const auto& v : v_even){
                if(v.first != v_even_max.first){
                    tmp += v.second;
                }
            }

            for (const auto& v : v_odd){
                if(v.first != v_odd_max2.first){
                    tmp += v.second;
                }
            }
            tmp_ans1 = tmp;
        }
        // 偶数に2番目の最頻値があるとき, その最頻値で書き換え
        if(v_even_max2.first != -1){
            int tmp =0;
            for (const auto& v : v_even){
                if(v.first != v_even_max2.first){
                    tmp += v.second;
                }
            }

            for (const auto& v : v_odd){
                if(v.first != v_odd_max.first){
                    tmp += v.second;
                }
            }
            tmp_ans2 = tmp;
        }
        // 1番目の最頻値が同じで、かつ2番目の候補が両方ともない
        // つまり全部おなじとき, 片方を全部書き換え
        if(v_even_max2.first == -1 && v_odd_max2.first == -1){
            tmp_ans1 = v_even_max.second;
        }
        // 偶数と奇数どっちの最頻値を動かしたほうが効率いいか
        ans = min(tmp_ans1,tmp_ans2);
    }
    // 最頻値が異なるので、素直にそれぞれ最頻値でない数字を最頻値に置き換えていけば良い
    else{
        for (const auto& v : v_even){
            if(v.first != v_even_max.first){
                ans += v.second;
            }
        }

        for (const auto& v : v_odd){
            if(v.first != v_odd_max.first){
                ans += v.second;
            }
        }
    }

    cout << ans << endl;

    return 0;
}