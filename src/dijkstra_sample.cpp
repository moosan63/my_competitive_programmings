
// この辺ほんとは構造体にしてポインタ渡すほうがたぶんシンプルになる

vector<vector<Int>> cost_to;
vector<Int> cost;
vector<int> done;

int dijkstra1n(int start, int goal, int N ){
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

int main() {
    Int city_num, road_num, time_limit;
    cin >> city_num >> road_num >> time_limit;

    cost_to = vector<vector<Int>>(city_num+1, vector<Int>(city_num+1, inf));
    cost = vector<Int>(city_num+1,inf);
    done = vector<int>(city_num+1,0);


    for(int i = 1; i<=city_num; i++){
        cost_to[i][i] = 0;
    }

    Int city_a, city_b, time_i;
    for(int i = 1; i <=road_num; i++){
        cin >> city_a >> city_b >> time_i;
        cost_to[city_a][city_b] = time_i;
        back_cost_to[city_b][city_a] = time_i;
    }

    dijkstra1n(1,city_num-1,city_num);



    return 0;
}