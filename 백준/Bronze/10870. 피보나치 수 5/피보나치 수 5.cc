#include <iostream>
using namespace std;

int fibonacci(int num) {
    if (num == 0) return 0;
    else if (num == 1) return 1;
    return fibonacci(num - 1) + fibonacci(num - 2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}