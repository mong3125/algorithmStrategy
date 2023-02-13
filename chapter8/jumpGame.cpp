/**
* 8.1 예제 외발 뛰기 (난이도: 하)
 * https://algospot.com/judge/problem/read/JUMPGAME
*/

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int board_size;
int cache[100][100];
int board[100][100];

bool canArrive();

bool canArrive() {
    queue<pair<int, int>> myQueue;

    myQueue.push(make_pair(board_size - 1, board_size - 1));
    while (!myQueue.empty()) {
        int y = myQueue.front().first;
        int x = myQueue.front().second;
        myQueue.pop();

        if (y < 0 || x < 0) continue;

        int &now = cache[y][x];

        if (now == -1) {
            int nextY = y + board[y][x];
            int nextX = x + board[y][x];
            if (nextY >= board_size && nextX >= board_size) {
                now = 0;
            } else if ((nextY == board_size - 1 && x == board_size - 1) || (nextX == board_size - 1 && y == board_size -1)) {
                now = 1;
            }
            if (nextY < board_size && now != 1) {
                now = (cache[nextY][x] == 1);
            }
            if (nextX < board_size && now != 1) {
                now = (cache[y][nextX] == 1);
            }
            myQueue.push(make_pair(y - 1, x));
            myQueue.push(make_pair(y, x - 1));
        }

    }

    return (cache[0][0] == 1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int cases;
    cin >> cases;

    for (int times = 0; times < cases; ++times) {
        cin >> board_size;

        memset(cache, -1, sizeof(cache));

        for (int i = 0; i < board_size; ++i) {
            for (int j = 0; j < board_size; ++j) {
                cin >> board[i][j];
            }
        }

        if (canArrive()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
