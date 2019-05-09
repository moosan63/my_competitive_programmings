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

int main() {
    Int N;
    cin >> N;
    Int ans =0;

    vi H = vi(N);
    rep(i,N){
        cin >> H[i];
    }

    Int tail=0, head=0;
    while(head <N && tail <N){

        while(H[head+1]>0 && head <N-1){
            head++;
        }
        int clear =0;
        for(int i=0; i<N; i++){
            clear += H[i];
        }
        if(clear == 0){
            break;
        }

        while(tail<=head){
            Int minimum = inf;
            for(int i=tail; i<=head; i++){
                if(H[i]>0){
                    minimum = min(H[i],minimum);
                }
            }

            for(int i=tail; i<=head; i++){
                if(H[i]>0){
                    H[i]-=minimum;
                }
            }
            ans+=minimum;

            // 尻を押す処理
            while(H[tail] == 0 && tail < N-1){
                tail++;
            }

            // 頭を引っ込める処理
            for(int i=tail; i<=head; i++){
                if(H[i]==0){
                    head = i;
                    break;
                }
            }

            if(tail>head){
                head=tail;
                break;
            }

            int clear2 =0;
            for(int i=0; i<N; i++){
                clear2 += H[i];
            }
            if(clear2 == 0){
                break;
            }
        }
    }



    cout << ans;
    return 0;
}