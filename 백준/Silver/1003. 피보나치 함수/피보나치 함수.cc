#include <stdio.h>

int zero[41] = { 0 }, one[41] = { 0 };

int main() {
    int t, n;
    zero[0] = 1;
    one[1] = 1;
    for (int i = 2; i <= 40; i++) {
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        printf("%d %d\n", zero[n], one[n]);
    }
}