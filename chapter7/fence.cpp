/**
* 7.4 울타리 잘라내기 (난이도: 중)
 * https://algospot.com/judge/problem/read/FENCE
*/

#include <iostream>
#define INF 100000
using namespace std;

int result = 0;
int list[20001];

void solution(int left, int right);
void largestRectangle(int left, int mid, int right);

void solution(int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        solution(left, mid);
        solution(mid + 1, right);
        largestRectangle(left, mid, right);
    }
}

void largestRectangle(int left, int mid, int right) {
    int i = mid;
    int j = mid + 1;
    int width = 0;
    int height = INF;
    int area;

    while (i >= left && j <= right) {
        width++;
        if (list[i] >= list[j]) {
            if (height > list[i]) height = list[i];
            i -= 1;
            area = width * height;
        } else {
            if (height > list[j]) height = list[j];
            j += 1;
            area = width * height;
        }

        if (area > result) result = area;
    }

    while (i >= left) {
        width++;
        if (height > list[i]) height = list[i];
        i -= 1;
        area = width * height;
        if (area > result) result = area;
    }

    while (j <= right) {
        width++;
        if (height > list[j]) height = list[j];
        j += 1;
        area = width * height;
        if (area > result) result = area;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int cases;
    cin >> cases;

    for (int times = 0; times < cases; ++times) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            cin >> list[i];
        }

        result = 0;
        solution(0, n - 1);
        cout << result << "\n";
    }

    return 0;
}
