#include <iostream>
#include <vector>

using namespace std;

void dfs(int v, int N);

vector<int> done(9,0);
int to[9][9];
int clear =0;
int main() {
    int N, M;
    cin >> N >> M;

    // 初期化
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            to[i][j] = 0;
        }
    }

    // パスの存在するところを1
    for(int i=0; i<M; i++){
        int ai, bi;
        cin >> ai >> bi;
        to[ai][bi]=1;
        to[bi][ai]=1;
    }

    // 始点は1
    done[1] = 1;
    dfs(1,N);


    cout << clear << endl;
    return 0;
}

void dfs(int v, int N) {
    // 全通りの数カウント
    int clear_judge =0;
    for(int i=1; i<=N; i++){
        clear_judge += done[i];
    }

    if(clear_judge==N){
        clear++;
    }


    for(int i = 1; i<=N; i++) {
        if (done[i] == 1 || to[v][i] == 0) {
            continue;
        }
        done[i] = 1;
        dfs(i, N);
        done[i] = 0;
    }
}