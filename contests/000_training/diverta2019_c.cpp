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
#include <math.h>
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
    Int N;
    cin >> N;

    vector<string> endA,startB,both;

    int count = 0;

    rep(i,N){
        string s;
        cin >>s;

        if(s[0]=='B'&&s[s.size()-1]=='A'){
            both.push_back(s);

        }else if (s[0]=='B'){
            startB.push_back(s);
        }else if (s[s.size()-1]=='A'){
            endA.push_back(s);
        }

        rep(i,s.size()-1){
            if(s[i]=='A'&&s[i+1]=='B'){
                count++;
            }
        }
    }

    int a_size = endA.size();
    int b_size = startB.size();
    int both_size = both.size();

    if(both_size>0){
        if(a_size+b_size>0){
            count += both_size+min(a_size,b_size);
        }else{
            count += both_size-1;
        }
    }else{
        count += min(a_size, b_size);
    }


    cout << count << endl;

    return 0;
}