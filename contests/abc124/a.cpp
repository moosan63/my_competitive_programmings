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
    int A, B;
    cin >> A >> B;
    int a,b,c,d;
    a = A + A-1;
    b = A + B;
    c = B + B-1;

    int max;
    if (a >= b && a>=c){
        max = a;
    }else if (b >= a && b >= c){
        max =b;
    }else {
        max = c;
    }

    cout << max << endl;
    return 0;
}