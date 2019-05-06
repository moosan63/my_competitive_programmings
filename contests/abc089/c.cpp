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
    int N;
    string answer;
    vector<int> t,x,y;
    cin >> N;

    for(int i=0; i<N; i++){
        int ti,xi,yi;
        cin >> ti >> xi >> yi;
        t.push_back(ti);
        x.push_back(xi);
        y.push_back(yi);
    }

    int start_x = 0;
    int start_y = 0;
    int time_now = 0;
    answer = "Yes";
    for(int i =0; i <N; i++){
        if (answer == "No") {
            continue;
        }
        int distance = (x[i] - start_x) + (y[i] - start_y);
        if (distance <= t[i]){
            int distance_remaining = t[i] - time_now - distance;
            if(distance_remaining%2 == 0){
                answer = "Yes";
                start_x = x[i];
                start_y = y[i];
                time_now = t[i];

            }else{
                answer = "No";
            }
        }else{
            answer = "No";
        }
    }

    cout << answer;
    return 0;
}