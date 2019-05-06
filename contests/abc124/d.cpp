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

int inst_max;
int count_max=0;
int count_reverse(string SS){
    int count =0;
    for (int i = 0; i <SS.size(); i++) {
        if(SS[i] == '1'){
            count++;
        }
    }
    return count;
}
void instruction(string SS, int l, int r){
    int c_l, c_r;
    string A = string(SS.size(), '9');
    int ans_count = 0;
    for (int i = 0; i <SS.size(); i++) {
        if (inst_max == 0) {
            A[i] = SS[i];
            continue;
        }
        if(l <= i && i <= r ){
            if (SS[i] == '0'){
                A[i] = '1';
            }else{
                A[i] = '0';
            }
        }else{
            A[i] = SS[i];
        }

    }

    ans_count = count_reverse(A);
    if(count_max < ans_count) {
        count_max = ans_count;
    }

    if (r !=-1 && l != -1){
        instruction(SS,c_l,c_r);
    }
}
int main() {
    string S;

    int N, K;
    cin >> N >> K;
    cin >> S;

    inst_max = K;

    instruction(S,-1,-1);

    cout << count_max << endl;
    return 0;
}



