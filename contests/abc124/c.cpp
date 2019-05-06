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
    string S;
    cin >> S;
    char prev;

    int count=0;
    for(int i = 0; i < S.size(); i++){
        if ( i == 0){
            prev = S[i];
            continue;
        }
        if(prev == S[i]){
            if (S[i] == '0'){
                prev = '1';
            }else{
                prev = '0';
            }
            count++;
        }else{
            prev = S[i];
        }
    }


    cout << count << endl;
    return 0;
}