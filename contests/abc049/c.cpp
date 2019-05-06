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

int main() {
    string S,T;
    string answer = "";
    vector<string> matcher = vector<string>(4,"");
    matcher[0]="dream";
    matcher[1]="dreamer";
    matcher[2]="erase";
    matcher[3]="eraser";
    T = "";
    queue<string> tmp;
    cin >> S;

    tmp.push(T);

    while(!tmp.empty()){
        T = tmp.front();
        if (T == S){
            answer = "YES";
            break;
        }
        tmp.pop();
        for(int j = 0; j < matcher.size(); j++){
            string calc_tmp = T + matcher[j];
            int tmp_size = calc_tmp.size() -1;
            if (T.size() > S.size()){continue;}
            if(S.compare(0,tmp_size,calc_tmp,0,tmp_size) == 0){
                tmp.push(calc_tmp);
            }
        }
    }

    if (T == S){
        answer = "YES";
    }else{
        answer = "NO";
    }

    cout << answer << endl;
    return 0;
}