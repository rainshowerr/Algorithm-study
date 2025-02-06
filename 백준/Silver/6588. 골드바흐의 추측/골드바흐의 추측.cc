#include <iostream>
#include <vector>

using namespace std;

bool visited[1000001] = {false,};
vector<int> sosu;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    // 에라토스테네스의 체
    for(int i = 2; i * i <= 1000000; i++) {
        if (!visited[i]) {
            for(int j = i * i; j <= 1000000; j += i) {
                visited[j] = true;
            }
        }
    }

    for(int i = 2; i * i <= 1000000; i++) {
        if (!visited[i]) sosu.push_back(i);
    }

    int n;
    bool flag = false;
    while(1) {
        cin >> n;
        if (n == 0) break;
        for(auto x: sosu) {
            if (!visited[n - x]) {
                cout << n << " = " << x << " + " << n - x << '\n';
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "Goldbach's conjecture is wrong.";
    }
}