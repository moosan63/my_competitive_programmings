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
using Int = long long;

int main() {
    int N;
    Int K;
    vector<Int> S;
    cin >> N >> K;

    for(int i=0; i<N; i++){
        int tmp;
        cin >> tmp;
        S.push_back(tmp);
    }

    int tail, head;
    tail = 0;
    head = 0;
    int max_len =0;
    Int tmp = 1;
    int tmp_len =0;

    while(true){
        tmp = tmp*S[head];
        if(tmp == 0){
            max_len = N;
            break;
        }
        if(tmp<=K){
            head++;
            tmp_len++;
            if(tmp_len > max_len){
                max_len = tmp_len;
            }
        }else{
            tmp = tmp/S[head];
            if(head != tail) {
                tmp = tmp/S[tail];
            }
            if(head <= tail){
                head++;
            }
            tail++;
            tmp_len--;
        }

        if(head == N){
            break;
        }
    }

    cout << max_len << endl;

    return 0;
}

