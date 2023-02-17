/**
* 8.2 와일드카드 (난이도: 중)
 * https://algospot.com/judge/problem/read/WILDCARD
*/

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[100][100];

string wild;
string file;
int wildLen;
int fileLen;

bool isMatched(int wildPos, int filePos);

bool isMatched(int wildPos, int filePos) {
    int &ret = cache[filePos][wildPos];
    if (ret != -1) return ret;

    if (wildPos < wildLen && filePos < fileLen &&
            (wild.at(wildPos) == file.at(filePos) || wild.at(wildPos) == '?')) {
        return ret = isMatched(wildPos + 1, filePos + 1);
    }

    if (wildPos == wildLen) return ret = (filePos == fileLen);

    if (wild.at(wildPos) == '*') {
        for (int i = filePos; i <= fileLen; ++i) {
            ret = isMatched(wildPos + 1, i);
            if (ret) return true;
        }
    }
    return (ret = false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int cases;
    cin >> cases;

    for (int times = 0; times < cases; ++times) {
        vector<string> result;
        cin >> wild;
        wildLen = (int)wild.size();

        int fileNum;
        cin >> fileNum;

        for (int i = 0; i < fileNum; ++i) {
            memset(cache, -1, sizeof(cache));
            cin >> file;
            fileLen = (int)file.size();
            if (isMatched(0, 0)) {
                result.push_back(file);
            }
        }
        sort(result.begin(), result.end());
        for (const string& output: result) {
            cout << output << "\n";
        }
    }

    return 0;
}