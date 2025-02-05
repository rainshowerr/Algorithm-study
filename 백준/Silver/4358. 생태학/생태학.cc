#include <iostream>
#include <vector>
#include <string>
#include <map>
// #include <fstream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin); // 파일 입력 테스트
    map<string, int> trees;
    string tree;
    
	int cnt = 0;
	while (getline(cin, tree)) { // cin >> tree는 공백 단위로 잘려서 getline해줘야함
        trees[tree]++;
        cnt++;
    }
    cout << fixed;
    cout.precision(4); // 소수점 개수 조절
    for(auto x: trees){
        cout << x.first << ' ';
        cout << (double)x.second / cnt * 100 << '\n';
    }
}