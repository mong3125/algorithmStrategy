/**
* 6.8 시계 맞추기 (난이도: 중)
* https://algospot.com/judge/problem/read/CLOCKSYNC
*/

#include <iostream>
#define INF 1234567890
using namespace std;

int clockSwitch[10][5] = {
        {0, 1, 2, -1, -1},
        {3, 7, 9, 11, -1},
        {4, 10, 14, 15, -1},
        {0, 4, 5, 6, 7},
        {6, 7, 8, 10, 12},
        {0, 2, 14, 15, -1},
        {3, 14, 15, -1, -1},
        {4, 5, 7, 14, 15},
        {1, 2, 3, 4, 5},
        {3, 4, 5, 9, 13}
};

int countSwitchOn(int switchNum, int clock[16], int switchCount);
void switchOn(int switchNum, int switchCount, int clock[16]);
void switchOff(int switchNum, int switchCount, int clock[16]);
bool isAllClockZero(int clock[16]);

int main() {
    ios::sync_with_stdio(false);
    cin.tie();

    int cases;
    cin >> cases;

    for (int times = 0; times < cases; ++times) {
        int clock[16];
        int input;
        for (int i = 0; i < 16; ++i) {
            cin >> input;
            clock[i] = input / 3 % 4;
        }

        int ret = countSwitchOn(0, clock, 0);
        if (ret != INF)
            cout << countSwitchOn(0, clock, 0) << "\n";
        else
            cout << -1 << "\n";
    }

    return 0;
}

int countSwitchOn(int switchNum, int clock[16], int switchCount) {
    if (isAllClockZero(clock)) return switchCount;

    if (switchNum > 9) return INF;

    int ret = INF;

    ret = min(ret, countSwitchOn(switchNum + 1, clock, switchCount));
    for (int i = 1; i <= 3; ++i) {
        switchOn(switchNum, i, clock);
        ret = min(ret, countSwitchOn(switchNum + 1, clock, switchCount + i));
        switchOff(switchNum, i, clock);
    }
    return ret;
}

void switchOn(int switchNum, int switchCount, int clock[16]) {
    int *mySwitch = clockSwitch[switchNum];
    for (int i = 0; i < 5 && mySwitch[i] >= 0; ++i) {
        clock[mySwitch[i]] = (clock[mySwitch[i]] + switchCount) % 4;
    }
}

void switchOff(int switchNum, int switchCount, int clock[16]) {
    int *mySwitch = clockSwitch[switchNum];
    for (int i = 0; i < 5 && mySwitch[i] >= 0; ++i) {
        clock[mySwitch[i]] = (clock[mySwitch[i]] - switchCount) % 4;
    }
}

bool isAllClockZero(int clock[16]) {
    for (int i = 0; i < 16; ++i) {
        if (clock[i]) return false;
    }
    return true;
}