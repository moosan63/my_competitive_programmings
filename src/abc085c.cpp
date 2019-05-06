#include <iostream>
using namespace std;

int main() {
    int count, TOTAL_YEN;
    cin >> count >> TOTAL_YEN;

    int a =0,b=0,c=0;
    int remain_count = count;
    int amount =0;
    for(int i = 1; i <= count; i++){
        amount += 10000;
        a++;
        if (amount > TOTAL_YEN) {
            amount -= 10000;
            a--;
            remain_count = count - i;
            break;
        }
    }

    for(int i = 1; i < remain_count; i++){
        amount += 5000;
        b++;
        if (amount > TOTAL_YEN) {
            amount -= 5000;
            b--;
            remain_count = remain_count -i;
            break;
        }
    }

    for(int i = 1; i < remain_count; i++){
        amount += 1000;
        c++;
        if (amount > TOTAL_YEN) {
            amount -= 1000;
            c--;
            break;
        }
    }
    if (amount == TOTAL_YEN) {
        cout << a << " " << b << " " << c << endl;
    }else {
        cout << "-1 -1 -1" << endl;
    }

    return 0;
}

