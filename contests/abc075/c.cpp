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
Int inf = 1000000000000000001LL;



int main() {
    vector<vector<int>> to;
    vector<int> done;
    vector<int> cut;
    int bridge =0;

    int N, M;
    cin >> N >> M;

    to = vector<vector<int>>(N+1,vector<int>(N+1,0));
    cut = vector<int>(N+1,0);
    done = vector<int>(N+1,0);
    for(int i=1; i<=M; i++){
        int a,b;
        cin >> a >> b;
        to[a][b] =1;
        to[b][a] =1;
    }

    int target=1;
    while(true){
        // clear check
        int all =0;
        for(int i=1; i<=N; i++){
            all+=done[i];
        }
        if(all ==N){
            break;
        }

        // search
        int to_count=0;
        for(int i=1; i<=N; i++){
            if (to[target][i] == 1){
                to_count++;
            }
            if(to_count >= 2 || to_count == 0){
                done[target]=1;
            }
        }

        if(to_count ==1){
            for(int i = 1; i<=N; i++){
                if(to[target][i]==1){
                    to[target][i]=0;
                    to[i][target]=0;
                    done[target]=1;
                    done[i] =0;
                    bridge++;
                    target = i;
                    break;
                }
            }
        }else{
            for(int i=1; i<=N; i++){
                if(done[i]==0){
                    target = i;
                }
            }
        }
    }

    cout << bridge << endl;
    return 0;
}