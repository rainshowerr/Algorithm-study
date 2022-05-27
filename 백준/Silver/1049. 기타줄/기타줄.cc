#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int n, m, bundle[50], piece[50], min_bundle = 1001, min_piece = 1001, ans;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> bundle[i] >> piece[i];
		min_bundle = min(min_bundle, bundle[i]); // 가장 값싼 묶음 찾기
		min_piece = min(min_piece, piece[i]); // 가장 값싼 낱개 찾기
	}
	min_bundle = min(min_bundle, min_piece * 6); // 6피스가 1묶음보다 싸다면 6피스를 1묶음으로 치환
	ans = min((n / 6 + 1) * (min_bundle), (n / 6) * min_bundle + (n % 6) * min_piece); // 전부 묶음으로 사기 vs (n-1)묶음 + 1낱개로 사기
	cout << ans;
}