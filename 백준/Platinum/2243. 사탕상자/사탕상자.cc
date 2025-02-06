#include <iostream>
#include <vector>
using namespace std;

// 인덱스를 사탕의 맛으로 생각
vector<long long> idx(2100000);

int n, leaf;

void edit_candy(int rank, int cnt) { // 사탕의 맛, 수정할 개수
	rank += leaf - 1;
	idx[rank] += cnt;
	rank /= 2;
	while (rank >= 1) {
		idx[rank] = idx[rank * 2] + idx[rank * 2 + 1];
		rank /= 2;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;

    for(leaf = 1; leaf < 1000000; leaf *= 2);

    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b;
        if (a == 1) {
            // b는 꺼낼 사탕의 순위
            int node = 1;
            while (node < leaf) {
                int lchild = node * 2;
                int rchild = node * 2 + 1;
                if (idx[lchild] >= b) // 사탕이 왼쪽에 있는 경우
                    node = lchild;
				else { // 사탕이 오른쪽에 있는 경우
					b -= idx[lchild];
					node = rchild;
				}
            }
			cout << node - leaf + 1 << '\n';
			edit_candy(node - leaf + 1, -1);
        }
        else if (a == 2) {
            // b는 넣을 사탕의 맛, c는 개수
            cin >> c;
			edit_candy(b, c);
        }
    }
}