#include <iostream>
#include <vector>
#include <utility>
using namespace std;


void quickSort(vector<int> &list, int left, int right);
int partition(vector<int> &list, int left, int right);

int main() {
    int number_count;
    cin >> number_count;

    vector<int> input_list;
    for (int count = 0; count < number_count; ++count) {
        int input;
        cin >> input;
        input_list.push_back(input);
    }

    quickSort(input_list, 0, input_list.size() - 1);

    for (int loop: input_list) {
        cout << loop << " ";
    }

    return 0;
}

void quickSort(vector<int> &list, int left, int right) {
    if (left >= right) return;

    int part = partition(list, left, right);

    quickSort(list, left, part-1);
    quickSort(list, part+1, right);
}

int partition(vector<int> &list, int left, int right) {
    int pivot = left;
    int left_point = left;
    int right_point = right;

    while (true) {
        while (list.at(pivot) > list.at(left_point)) left_point++;
        while (list.at(pivot) < list.at(right_point)) right_point--;

        if (left_point < right_point)
            swap(list[left_point], list[right_point]);
        else
            break;
    }
    swap(list[pivot], list[right_point]);
    return right_point;
}