/**
* 6.3 문제: 소풍 (PICNIC, 난이도 하)
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

int numberOfCases = 0;
int num_student;
map<int, vector<int>> friends;


void numberMatch(bool* have_pair, int index);
bool isAllTrue(bool list[10]);

int main() {
    int cases;
    cin >> cases;

    for (int time = 0; time < cases; ++time) {
        numberOfCases = 0;

        cin >> num_student;

        int num_pair;
        cin >> num_pair;

        friends.clear();
        for (int i = 0; i < num_pair; ++i) {
            int a, b;
            cin >> a >> b;
            friends[a].push_back(b);
            friends[b].push_back(a);
        }

        bool have_pair[100];   // 짝이 있는지 여부
        fill_n(have_pair, 100, true);
        for (int i = 0; i < num_student; ++i) {
            have_pair[i] = false;
        }

        numberMatch(have_pair, 0);
        cout << numberOfCases << "\n";
    }
    return 0;
}

void numberMatch(bool* have_pair, int index) {
    // 모두 짝이 있을때
    if (isAllTrue(have_pair)) {
        numberOfCases += 1;
        return;
    }

    // 끝까지 짝을 지었지만 짝이 없는 친구가 있을때
    if (index >= num_student) {
        return;
    }

    if (!have_pair[index]) {    // 짝이 없을때
        for (int myFriend: friends[index]) { // 친구중 한명을 선택해서
            if (!have_pair[myFriend]) { // 그 친구도 짝이 없다면 짝지음
                have_pair[index] = have_pair[myFriend] = true;
                numberMatch(have_pair, index + 1);
                have_pair[index] = have_pair[myFriend] = false;
            }
        }
    }
    else {
        numberMatch(have_pair, index + 1);
    }
}

bool isAllTrue(bool* list) {
    for (int i = 0; i < num_student; ++i) {
        if (!list[i]) return false;
    }
    return true;
}
