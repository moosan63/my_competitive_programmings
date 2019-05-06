#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    map<int, vector<pair<int,int>>> m;
    for (int i = 0; i<M; i++){
        int point_a, point_b, time;
        cin >> point_a >> point_b >> time;
        pair<int,int> a_to_b, b_to_a;

        vector<pair<int,int>> points_a;
        a_to_b.first = point_b;
        a_to_b.second = time;
        points_a.push_back(a_to_b);
        m[point_a] = points_a;

        vector<pair<int,int>> points_b;
        b_to_a.first = point_a;
        b_to_a.second = time;
        points_b.push_back(b_to_a);
        m[point_b] = points_b;

    }
    return 0;
}