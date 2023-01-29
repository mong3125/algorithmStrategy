/**
* 6.5 게임판 덮기 (난이도: 하)
 * https://algospot.com/judge/problem/read/BOARDCOVER
*/

#include <iostream>
using namespace std;

// L자 타일 모양
int tile[12][2][2] = {
        {{1, 0}, {1, -1}},
        {{1, 0}, {1, 1}},
        {{-1, 0}, {-1, -1}},
        {{-1, 0}, {-1, 1}},
        {{0, 1}, {1, 1}},
        {{0, 1}, {-1, 1}},
        {{0, -1}, {1, -1}},
        {{0, -1}, {-1, -1}},
        {{1, 0}, {0, 1}},
        {{1, 0}, {0, -1}},
        {{-1, 0}, {0, 1}},
        {{-1, 0}, {0, -1}}
};

int h, w;   // 세로, 가로

int coverTile(int y, int x, char (*board)[20]);
bool canCover(int type, char (*board)[20], int y, int x);
bool isAllTileBlack(char (*board)[20]);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int cases;  // 테스트 케이스 수
    cin >> cases;

    for (int times = 0; times < cases; ++times) {
        // 타일 입력하기
        cin >> h >> w;

        char board[20][20];
        for (int i = 0; i < h; ++i) {
            cin >> board[i];
        }

        // 흰색 타일 개수 세기
        int numberWhileTile = 0;
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (board[i][j] == '.') numberWhileTile += 1;
            }
        }

        // 흰색 타일 개수가 3의 배수가 아니면 경우의 수 없음
        if (numberWhileTile % 3 != 0) {
            cout << 0 << "\n";
        } else {
            cout << coverTile(0, 0, board) << "\n";
        }
    }

    return 0;
}

int coverTile(int y, int x, char (*board)[20]) {
    // y가 범위를 벗어났을때
    if (y >= h) {
        if (isAllTileBlack(board))
            return 1;
        else
            return 0;
    }
    // x가 범위를 벗어났을때
    else if (x >= w) {
        return coverTile(y + 1, 0, board);
    }

    int ret = 0;
    if (board[y][x] == '#') {
        ret = coverTile(y, x + 1, board);
    }
    else {
        for (int type = 0; type < 12; ++type) {
            if (canCover(type, board, y, x)) {
                board[y][x] = board[y + tile[type][0][0]][x + tile[type][0][1]] = board[y + tile[type][1][0]][x + tile[type][1][1]] = '#';
                ret += coverTile(y, x + 1, board);
                board[y][x] = board[y + tile[type][0][0]][x + tile[type][0][1]] = board[y + tile[type][1][0]][x + tile[type][1][1]] = '.';
            }
        }
    }
    return ret;
}

bool canCover(int type, char (*board)[20], int y, int x) {
    for (int i = 0; i < 2; ++i) {
        const int ny = y + tile[type][i][0];
        const int nx = x + tile[type][i][1];
        if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
            return false;
        }

        if (board[ny][nx] == '#') {
            return false;
        }
    }
    return true;
}

bool isAllTileBlack(char (*board)[20]) {
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (board[i][j] == '.') return false;
        }
    }
    return true;
}