/**
 * m개의 n미만의 수를 모두 출력하는 재귀 프로그램
 */


#include <iostream>
#include <vector>
using namespace std;

vector<int> stackPrintNum;
void recursivePrintToZero(int n, int m);
void callRecursivePrintToZero(int n, int m);

int main() {
    callRecursivePrintToZero(7, 4);
}

void callRecursivePrintToZero(int n, int m) {
    for (int i = m; i < n + 1; ++i) {
        recursivePrintToZero(i, m);
    }
}

void recursivePrintToZero(int n, int m) {
    // 기저사례: n이 0일때 return
    if (n == 0) return;

    stackPrintNum.push_back(n - 1);
    // m == 1일때 출력
    if (m == 1) {
        for (int i : stackPrintNum) {
            cout << i << " ";
        }
        cout << "\n";
        stackPrintNum.pop_back();
        return;
    }

    for (int i = m-1; i < n; ++i) {
        recursivePrintToZero(i, m - 1);
    }
    stackPrintNum.pop_back();
}