#include <iostream>
#include <vector>

using namespace std;
using Int = long long;

vector<vector<Int>> cost_to;
vector<Int> cost;
vector<int> done;

vector<vector<Int>> back_cost_to;
vector<Int> back_cost;
vector<int> back_done;
const Int inf = 100000000000000000LL;

int dijkstra1n(int start, int goal, int N, ){
    Int min, target;
    target = -1;
    cost[start] = 0;
    while(true){
        int all=0;
        min = inf;
        for(int i=1; i<=N; i++){
            if(done[i] ==0 && min > cost[i]){
                min = cost[i];
                target = i;
            }
            all += done[i];
        }

        if (all == N) {
            return cost[goal];
        }

        for(int i=1; i<=N; i++){
            if(cost[i] > cost[target]+cost_to[target][i]) {
                cost[i] = cost[target]+cost_to[target][i];
            }
        }
        done[target] = 1;
    }
}

int dijkstra1nback(int start, int goal, int N){
    Int min, target;
    target = -1;
    back_cost[start] = 0;
    while(true){
        int all=0;
        min = inf;
        for(int i=1; i<=N; i++){
            if(back_done[i] ==0 && min > back_cost[i]){
                min = back_cost[i];
                target = i;
            }
            all += back_done[i];
        }

        if (all == N) {
            return back_cost[goal];
        }

        for(int i=1; i<=N; i++){
            if(back_cost[i] > back_cost[target]+back_cost_to[target][i]) {
                back_cost[i] = back_cost[target]+back_cost_to[target][i];
            }
        }
        back_done[target] = 1;
    }
}


int main() {
    Int city_num, road_num, time_limit;
    cin >> city_num >> road_num >> time_limit;

    cost_to = vector<vector<Int>>(city_num+1, vector<Int>(city_num+1, inf));
    cost = vector<Int>(city_num+1,inf);
    done = vector<int>(city_num+1,0);

    back_cost_to = vector<vector<Int>>(city_num+1, vector<Int>(city_num+1, inf));
    back_cost = vector<Int>(city_num+1,inf);
    back_done = vector<int>(city_num+1,0);


    vector<Int> golds = vector<Int>(city_num+1,0);
    for (int i =1; i <= city_num; i ++) {
        Int gold;
        cin >> gold;
        golds[i] = gold;
    }

    for(int i = 1; i<=city_num; i++){
        cost_to[i][i] = 0;
        back_cost_to[i][i] =0;
    }

    Int city_a, city_b, time_i;
    for(int i = 1; i <=road_num; i++){
        cin >> city_a >> city_b >> time_i;
        cost_to[city_a][city_b] = time_i;
        back_cost_to[city_b][city_a] = time_i;
    }
    Int gold_max = 0;

    dijkstra1n(1,city_num-1,city_num);
    dijkstra1nback(1,city_num-1,city_num);
    for (int i=1; i<=city_num; i++){
        Int go = cost[i];
        Int back = back_cost[i];
        Int time_remain = (time_limit - (go + back) );
        Int tmp_gold = time_remain*golds[i];
        if(tmp_gold>gold_max){
            gold_max = tmp_gold;
        }
    }

    cout << gold_max << endl;


    return 0;
}


