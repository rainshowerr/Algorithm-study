#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, alpha[26] = { 0, };
    string word[10];
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> word[i];
    // 알파벳 배열에 자릿수 가중치 더해주기 (ex. alpha[0] = 10010 : a가 10000의 자리와 10의 자리에 위치한 경우)
    for(int i = 0; i < n; i++){
        int digit = 1;
        for(int j = word[i].length() - 1; j >= 0; j--){
            int k = word[i][j] - 'A';
            alpha[k] += digit;
            digit *= 10;
        }
    }
    // 가중치가 높은 순서대로 정렬
    priority_queue<pair<int, int>> q;
    for(int i = 0; i < 26; i++){
        if (alpha[i])
            q.push({alpha[i], i});
    }
    // 가중치가 높은 순서대로 9에서부터 1 줄여가며 곱해서 ans에 더해줌
    int ans = 0;
    int temp = 9;
    while(!q.empty()){
        ans += q.top().first * temp;
        q.pop();
        temp--;
    }
    cout << ans;
}