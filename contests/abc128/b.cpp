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
Int printX(Int r, Int D, Int X, int count){
    if(count == 10){
        return 0;
    }
    Int nextX = r*X - D;
    cout<< nextX <<endl;
    printX(r,D,nextX,count+1);

}
int main() {
    int N;
    vector<string> S;
    vi P;
    cin >> N;
    S = vector<string>(N);
    P = vi(N);

    map<string,priority_queue<int>> sorted_towns;
    map<string,map<int,int>> p_rank;
    rep(i,N){
        cin >> S[i] >> P[i];
        sorted_towns[S[i]].push(P[i]);
        p_rank[S[i]][P[i]] = i;
    }
    vector<string> originS = S;
    sort(S.begin(),S.end());

    map<string,Int>  s_rank;

    rep(i,N){
        if(s_rank[S[i]] ==0){
            string aa = S[i];
            s_rank[S[i]]= i+1;
        }
    }

    rep(i,N){

            string aa = S[i];
            s_rank[S[i]];
            cout << s_rank[S[i]] << " " << aa << endl;

    }


    rep(i,N){
        int ans =0;
        string nowS = originS[i];
        priority_queue<int> a = sorted_towns[nowS];
        vector<int> b;
        while(!a.empty()){
            b.push_back(a.top());
            a.pop();
        }
        for(int j = 0; j<b.size(); j++){
            if(P[p_rank[S[i]][P[i]]] == b[j]){
                int rank = s_rank[S[i]];
                ans= j+s_rank[S[i]];
                cout << ans << endl;
            }
        }

    }

    return 0;
}
