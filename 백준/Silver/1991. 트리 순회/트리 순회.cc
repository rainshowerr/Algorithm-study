#include <iostream>
using namespace std;

struct node {
	char left;
	char right;
};

node a['Z' + 1];

void preorder(char x) {
	if (x == '.') return;
	cout << x;
	preorder(a[x].left);
	preorder(a[x].right);
}

void inorder(char x) {
	if (x == '.') return;
	inorder(a[x].left);
	cout << x;
	inorder(a[x].right);
}

void postorder(char x) {
	if (x == '.') return;
	postorder(a[x].left);
	postorder(a[x].right);
	cout << x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char x, y, z;
		cin >> x >> y >> z;
		a[x].left = y;
		a[x].right = z;
	}
	preorder('A'); cout << '\n';
	inorder('A'); cout << '\n';
	postorder('A'); cout << '\n';
}