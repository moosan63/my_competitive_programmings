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
using pii = pair<Int,Int>;
using mapis = unordered_map<Int,string>;
using mapii = unordered_map<Int,Int>;

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

Int LCM(Int a, Int b){
    return a*b/GCD(a,b);
}

int main() {
    Int N,K;
    cin >> N >> K;

    vi A = vi(N);
    rep(i,N){
        cin >> A[i];
    }
    sort(A.begin(),A.end());

    vi F = vi(N);

    rep(i,N){
        cin>>F[i];
    }
    sort(F.begin(),F.end(),greater<>());


    Int max =-1;
    rep(i,N){

        if(A[i]*F[i] > max){
            max = A[i]*F[i];
        }
    }

    int total=0;
    rep(i,N){
        total+=A[i];
    }

    if(total<=K){
        cout << 0 << endl;
        return 0;
    }

    Int left = 0;
    Int right = max;

    Int ans = inf;
    while(left<=right){
        Int mid = left+right / 2;
        Int total_training =0;
        Int tmp_max = -1;
        rep(i,N){
            Int cost =A[i]*F[i];
            if(mid<cost){
                Int target = cost-mid;
                Int this_time_training;
                if(target%F[i]==0){
                    this_time_training = target/F[i];
                }else{
                    this_time_training = (target/F[i])+1;
                }
                total_training+=this_time_training;

                Int this_time_cost;
                if(A[i]-this_time_training>0){
                    this_time_cost = (A[i]-this_time_training)*F[i];
                }else{
                    this_time_cost = 0;
                }


                if(tmp_max < this_time_cost){
                    tmp_max = this_time_cost;
                }
            }
        }

        if(total_training<=K){
            if(tmp_max<ans&&tmp_max !=-1){
                ans = tmp_max;
            }
            left = (left+mid)/2;
        }else{
            right = (mid+right)/2;
        }
    }



    cout << ans << endl;


    return 0;
}