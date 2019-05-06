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
    int N, K;
    string S;
    cin >> N >> S >>K;
    char target = S[K-1];
    string answer = "";

    for(int i=0; i<S.size(); i++){
        if(S[i] != target){
            cout << '*';
        }else{
            cout << S[i];
        }
    }

    cout << endl;
    return 0;
}