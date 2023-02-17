/**
* 8.4 예제 삼각형 위의 최대 경로 (난이도: 하)
 * https://algospot.com/judge/problem/read/TRIANGLEPATH
 * 메모이제이션을 적용한 예제 풀이
*/

#include <iostream>
#include <cstring>
using namespace std;

int n; // 삼각형의 크기
int triangle[100][100]; // 입력받는 삼각형
int cache[100][100];    // 각 지점에서의 부분 최대 합

int path(int y, int x);

int path(int y, int x) {
    if (y == n -1) return triangle[y][x];

    int &ret = cache[y][x];
    if (ret != -1) return ret;

    return ret = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int cases;  // test case 횟수
    cin >> cases;

    for (int times = 0; times < cases; ++times) {
        cin >> n;

        memset(cache, -1, sizeof(cache));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                cin >> triangle[i][j];
            }
        }

        cout << path(0, 0) << "\n";
    }

    return 0;
}