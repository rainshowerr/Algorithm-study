#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<long long> num(1000001);
    vector<long long> index_tree(2100000);
    int n; // 수의 개수
    int m; // 변경이 일어나는 횟수
    int k; // 구간함을 구하는 횟수
    
    cin >> n >> m >> k;

    int leaf;
    for (leaf = 1; leaf < n; leaf *= 2);

    // 수 입력을 받으며 인덱스 트리의 리프노드를 함께 구성
    for(int i = 0; i < n; i++) {
        long long nn;
        cin >> nn;
        num[i] = nn;;
        index_tree[leaf + i] = nn;
    }

    // 인덱스 트리 구성
    for (int i = leaf - 1; i >= 1; i--)
    {
        index_tree[i] = index_tree[i * 2] + index_tree[i * 2 + 1];
    }

    int a, b;
    long long c;
    for (int i = 1; i <= m + k; i++)
    {
        cin >> a >> b >> c;

        if (a == 1)
        {
            b += leaf - 1;
            index_tree[b] = c;
            b /= 2;
            while (b >= 1)
            {
                index_tree[b] = index_tree[b * 2] + index_tree[b * 2 + 1];
                b /= 2;
            }
        }
        else
        {
            b += leaf - 1;
            c += leaf - 1;

            long long sum = 0;
            while (b <= c)
            {
                if (b % 2 == 1) sum += index_tree[b++];
                if (c % 2 == 0) sum += index_tree[c--];

                b /= 2;
                c /= 2;
            }
            cout << sum << "\n";
        }
    }
    return 0;
}