/**
 * 7.3 쿼드 트리 뒤집기 (난이도: 하)
 * https://algospot.com/judge/problem/read/QUADTREE
 */

#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& iter);

// string::iterator iter;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int cases;
    cin >> cases;

    for (int times = 0; times < cases; ++times) {
        string input;
        cin >> input;
        string::iterator iter = input.begin();

        cout << reverse(iter) << "\n";
    }

    return 0;
}

string reverse(string::iterator& iter) {
    char head = *iter;
    ++iter;

    if (head == 'x') {
        string a = reverse(iter);
        string b = reverse(iter);
        string c = reverse(iter);
        string d = reverse(iter);
        return string("x") + c + d + a + b;
    } else {
        return string(1, head);
    }
}