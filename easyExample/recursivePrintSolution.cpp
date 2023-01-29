#include <iostream>
#include <vector>
using namespace std;

void printPicked(const vector<int> &picked);

void pick(int n, vector<int> &picked, int toPick);

int main() {
    vector<int> *list = new vector<int>;
    pick(7, *list, 4);
}

void printPicked(const vector<int> &picked) {
    for (int i : picked) {
        cout << i << " ";
    }
    cout << "\n";
}

void pick(int n, vector<int> &picked, int toPick) {
    if (toPick == 0) {
        printPicked(picked);
        return;
    }

    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for (int next = smallest; next < n; ++next) {
        picked.push_back(next);
        pick(n, picked, toPick - 1);
        picked.pop_back();
    }
}