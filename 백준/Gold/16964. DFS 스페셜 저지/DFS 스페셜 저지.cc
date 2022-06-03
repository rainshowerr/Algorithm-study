#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> node[100001];
vector<int> user;
vector<int> ans;
int order[100001];
bool check[100001] = { false };

bool cnt(int a, int b){
    return order[a] < order[b];
}

void dfs(int x) {
    if (check[x] == true)
        return;
    check[x] = true;
    ans.push_back(x);
    for (int y : node[x]) {
        if (check[y] == false) {
            dfs(y);
        }
    }
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int from, to;
        cin >> from >> to;
        node[from].push_back(to);
        node[to].push_back(from);
    }
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        user.push_back(a);
        order[a] = i;
    }
    for (int i = 1; i <= n; i++)
        sort(node[i].begin(), node[i].end(), cnt);
    dfs(1);
    if (user == ans)
        cout << '1';
    else
        cout << '0';
}