/**
* 8.4 예제 삼각형 위의 최대 경로 (난이도: 하)
 * https://algospot.com/judge/problem/read/TRIANGLEPATH
*/

#include <iostream>
using namespace std;

int triangle[100][100];
int maxSum[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int cases;  // test case 횟수
    cin >> cases;

    for (int times = 0; times < cases; ++times) {
        int n;  // 삼각형 크기
        cin >> n;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j <= i; ++j) {
                cin >> triangle[i][j];
            }
        }

        for (int i = 0; i <= n - 1; ++i) {
            maxSum[n-1][i] = triangle[n-1][i];
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                maxSum[i][j] = max(maxSum[i + 1][j], maxSum[i + 1][j + 1]) + triangle[i][j];
            }
        }

        cout << maxSum[0][0] << "\n";
    }

    return 0;
}
