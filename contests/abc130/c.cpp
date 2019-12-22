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


int main() {
    long double W,H,x,y;
    cin >> W >> H >> x >> y;

    long double x_1,x_2;
    long double y_1,y_2;

    //正方形か長方形か
    if (H==W){
        // x,yが内部のときは普通に長方形に切ってやるのが小さいのが最大になる
        if(x>0&&y>0 && x<W&&y<H){

            // 正方形かつx,yが対角線上の点なら半分にするのがベスト
            if(x==y || W-x == y) {
                cout <<std::fixed<<std::setprecision(10) << W*H/2 << " ";
                if(x==y && int(W)%2==0 && int(W)/2 == x){
                    // ど真ん中のときだけ複数ある
                    cout << 1 << endl;
                }else{
                    cout << 0 << endl;
                }
            }else{
                // Xで分割するパターン
                x_1 = x*H*1.0;
                x_2 = (W-x)*H*1.0f;


                // Yで分割するパターン
                y_1 = W*y*1.0f;
                y_2 = W*(H-y)*1.0f;

                // 小さいやつの最大を取る

                long double x_ans = min(x_1,x_2);
                long double y_ans = min(y_1,y_2);

                cout <<std::fixed<<std::setprecision(10) << max(x_ans, y_ans) << " ";

                if(x_ans == y_ans){
                    cout << 1 << endl;
                }else{
                    cout << 0 << endl;
                }
            }
        }else if( x==0 || y==0 || x==W || y==H){
            //x,yが周上にいるときは面積の半分を作ってやる
            cout <<std::fixed<<std::setprecision(10) << W*H/2 << " ";
            cout << 0 << endl; // かならず半分にわける1個しかない
        }

    }else{
        // 長方形ならパターンが減る

        // x,yが内部のときは普通に長方形に切ってやるのが小さいのが最大になる
        if(x>0&&y>0 && x<W&&y<H){
            // Xで分割するパターン
            x_1 = x*H*1.0;
            x_2 = (W-x)*H*1.0f;


            // Yで分割するパターン
            y_1 = W*y*1.0f;
            y_2 = W*(H-y)*1.0f;

            // 小さいやつの最大を取る

            long double x_ans = min(x_1,x_2);
            long double y_ans = min(y_1,y_2);

            cout <<std::fixed<<std::setprecision(10) << max(x_ans, y_ans) << " ";

            if(x_ans == y_ans){
                cout << 1 << endl;
            }else{
                cout << 0 << endl;
            }
            //(x==0&&y==0) || (x==0&&y==H) || (x==W&&y==0) || (x==W&&y==H) || (x==0)
        }else if( x==0 || y==0 || x==W || y==H){
            //x,yが周上にいるときは面積の半分を作ってやる
            cout <<std::fixed<<std::setprecision(10) << W*H/2 << " ";
            cout << 0 << endl; // かならず半分にわける1個しかない
        }
    }



    return 0;
}