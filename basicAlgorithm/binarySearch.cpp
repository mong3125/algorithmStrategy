#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(const vector<int> &list, int target, int left, int right);

int main() {
    vector<int> input_list;

    int input_count;
    cin >> input_count;

    for (int i = 0; i < input_count; ++i) {
        int input;
        cin >> input;
        input_list.push_back(input);
    }

    sort(input_list.begin(), input_list.end());

    int find_number;
    cin >> find_number;

    cout << find_number << "'s index: " << binarySearch(input_list, find_number, 0, input_list.size() - 1) << endl;

    return 0;
}

int binarySearch(const vector<int> &list, int target, int left, int right) {
    if (left >= right) return -1;

    int mid = (left + right) / 2;

    if (list[mid] > target)
        return binarySearch(list, target, left, mid - 1);
    else if (list[mid] < target)
        return binarySearch(list, target, mid + 1, right);
    else
        return mid;

    return 0;
}
