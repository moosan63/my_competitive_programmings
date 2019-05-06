//
// Created by 村上怜 on 2019-04-10.
//
#include <iostream>
#include <vector>
#include <queue>

int main() {
    int A;
    int ALL = 2025;
    char ans[81];
    std::cin >> A;
    int diff = ALL - A;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j<=9; j++) {
            if (diff == i*j){
                sprintf(ans,"%d x %d", i,j);
                std::cout << ans << std::endl;
            }
        }
    }

    return 0;
}
