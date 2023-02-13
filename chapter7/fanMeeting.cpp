/**
* 7.6 팬미팅 (난이도: 상)
 * https://algospot.com/judge/problem/read/FANMEETING
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void organize(vector<int> &a);

void addTo(vector<int> &a, const vector<int> &b, int k);

void subFrom(vector<int> &a, const vector<int> &b);

vector<int> multiply(const vector<int> &a, const vector<int> &b);

vector<int> karatsuba(const vector<int> &a, const vector<int> &b);

int hugs(const string &members, const string &fans);

// 숫자 자리 정리
void organize(vector<int> &a) {
    int an = a.size();
    for (int i = 0; i < an; ++i) {
        int now = a[i];
        int index = i;
        while (now > 10) {
            now /= 10;
            index += 1;
            if (index >= an) {
                a[index] = now % 10;
            } else {
                a[index] += now % 10;
            }
        }
    }
}

// 자리 올림 생략 덧셈
void addTo(vector<int> &a, const vector<int> &b, int k) {
    int an = a.size();
    int bn = b.size();

    for (int i = 0; i < bn; ++i) {
        if (i + k >= an) {
            a.push_back(b[i]);
        } else {
            a[i + k] += b[i];
        }
    }
}

void subFrom(vector<int> &a, const vector<int> &b) {
    int an = a.size();
    int bn = b.size();

    for (int i = 0; i < bn; ++i) {
        a[i] -= b[i];
    }
}

vector<int> multiply(const vector<int> &a, const vector<int> &b) {
    int an = a.size();
    int bn = b.size();
    vector<int> result(an + bn);

    for (int i = 0; i < an; ++i) {
        for (int j = 0; j < bn; ++j) {
            result[i + j] += a[i] * b[j];
        }
    }

    return result;
}

vector<int> karatsuba(const vector<int> &a, const vector<int> &b) {
    int an = a.size();
    int bn = b.size();

    // b가 a보다 큰 경우
    if (an < bn) return karatsuba(b, a);
    // a나 b가 비어 있는 경우
    if (an == 0 || bn == 0) return vector<int>();
    // 숫자 크기가 작을때 단순 곱셈
    if (an <= 100) return multiply(a, b);

    int half = an / 2;

    vector<int> a0(a.begin(), a.begin() + half);
    vector<int> a1(a.begin() + half, a.end());
    vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
    vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

    //
    vector<int> z0 = karatsuba(a0, b0);
    vector<int> z2 = karatsuba(a1, b1);
    addTo(a0, a1, 0);
    addTo(b0, b1, 0);
    vector<int> z1 = karatsuba(a0, b0);
    subFrom(z1, z0);
    subFrom(z1, z2);

    vector<int> ret;
    addTo(ret, z0, 0);
    addTo(ret, z1, half);
    addTo(ret, z2, half + half);

    return ret;
}

int hugs(const string &members, const string &fans) {
    int member_n = (int)members.size();
    int fans_n = (int)fans.size();

    vector<int> members_list(member_n);
    vector<int> fans_list(fans_n);

    for (int i = 0; i < member_n; ++i) {
        members_list[i] = (members[i] == 'M');
    }
    for (int i = 0; i < fans_n; ++i) {
        fans_list[fans_n - i - 1] = (fans[i] == 'M');
    }

    vector<int> ret = karatsuba(members_list, fans_list);

    int count = 0;
    for (int i = member_n - 1; i < fans_n; ++i) {
        if (ret[i] == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();

    int cases;
    cin >> cases;

    for (int times = 0; times < cases; ++times) {
        string members;
        cin >> members;

        string fans;
        cin >> fans;

        cout << hugs(members, fans) << "\n";
    }

    return 0;
}
