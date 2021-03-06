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
    Int N;
    vi A,B;
    cin >> N;
    A = vi(N+1);
    B = vi(N);

    rep(i,N+1){
        cin>>A[i];
    }
    rep(i,N){
        cin>>B[i];
    }

    Int total = 0;

    rep(i,N){
        if(B[i]>A[i]){
            total+= A[i];
            B[i]=B[i]-A[i];
            A[i]=0;
        }else{
            total+= B[i];
            A[i] = A[i]-B[i];
            B[i]=0;
        }

        if(B[i]>A[i+1]){
            total+= A[i+1];
            B[i]=B[i]-A[i+1];
            A[i+1]=0;
        }else{
            total+= B[i];
            A[i+1] = A[i+1]-B[i];
            B[i]=0;
        }

    }

    cout << total << endl;

    return 0;
}