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
using namespace std;

int N;
string S;
int count_b(int start){
    int b_cnt=0;
    for(int i = start; start<N; i++){
        if(S[i]=='#'){
            b_cnt++;
        }else{
            return b_cnt;
        }
    }
    return b_cnt;
}

int count_w(int start){
    int w_cnt=0;
    for(int i = start; start<N; i++){
        if(S[i]=='.'){
            w_cnt++;
        }else{
            return w_cnt;
        }
    }
    return w_cnt;
}
int main() {
    cin >> N >> S;

    int b_tmp =0;
    int w_tmp =0;
    int answer = 0;

    int i =0;
    while(i<N){
        if(S[i] == '.'){
            i++;
        }else{
            break;
        }
    }
    while(i<N){
        b_tmp+=count_b(i);
        i+=b_tmp;
        w_tmp+=count_w(i);
        i+=w_tmp;

        answer += min(b_tmp,w_tmp);
        w_tmp = 0;
        b_tmp = 0;
    }

    cout << answer << endl;
    return 0;
}