#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

vector<string> grid_board;
vector<string> input_word_list;

const int MAX_WORD_NUMBER{11};
const int MAX_GRID_RANGE{5};
int cache[MAX_WORD_NUMBER][MAX_GRID_RANGE][MAX_GRID_RANGE];

bool hasWord(int y, int x, int word_index, int alphabet_index);
bool inRange(int y, int x);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int cases;  // 시행 횟수
    cin >> cases;

    for (int times = 0; times < cases; ++times) {
        // cache 초기화
        memset(cache, -1, sizeof(cache));

        // 입력
        for (int i = 0; i < 5; ++i) {
            string input;
            cin >> input;
            grid_board.push_back(input);
        }

        int word_num = 0;   // 단어 개수
        cin >> word_num;

        for (int i = 0; i < word_num; ++i) {
            string input;
            cin >> input;
            input_word_list.push_back(input);
        }

        for (int word_index = 0; word_index < word_num; ++word_index) {
            bool isFound = false;
            for (int y = 0; y < 5 && !isFound; ++y) {
                for (int x = 0; x < 5; ++x) {
                    if (hasWord(y, x, word_index, 0)) {
                        isFound = true;
                        break;
                    }
                }
            }
            if (isFound) {
                cout << input_word_list.at(word_index) << " " << "YES\n";
            }
            else {
                cout << input_word_list.at(word_index) << " " << "NO\n";
            }
        }
    }

    return 0;
}

const int dx[8] = {1, 1, 0, -1, -1, -1,  0,  1};
const int dy[8] = {0, 1, 1,  1,  0, -1, -1, -1};

stack<pair<int, int>> cache_stack;

bool hasWord(int y, int x, int word_index, int alphabet_index) {
    // out of range
    if (!inRange(y, x)) return false;

    // 메모이제이션
    int &ret = cache[word_index][y][x];
    if (ret != -1) return ret;

    if (grid_board.at(y).at(x) != input_word_list.at(word_index).at(alphabet_index)) return false;
    cache_stack.push(make_pair(y, x));

    if (input_word_list.at(word_index).size() == alphabet_index + 1) {
        while (!cache_stack.empty()) {
            int stack_y = cache_stack.top().first;
            int stack_x = cache_stack.top().second;
            cache[word_index][stack_y][stack_x] = 1;
            cache_stack.pop();
        }
        return true;
    }

    for (int direction = 0; direction < 8; ++direction) {
        if (hasWord(y + dy[direction], x + dx[direction], word_index, alphabet_index + 1)) {
            return true;
        }
    }
    cache_stack.pop();
    return false;
}

bool inRange(int y, int x) {
    if (y < 0 || x < 0 || y > 4 || x > 4) return false;
    else return true;
}