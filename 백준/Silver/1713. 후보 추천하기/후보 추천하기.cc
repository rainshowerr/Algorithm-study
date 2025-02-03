#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	if (a.second.first == b.second.first) {
		return a.second.second < b.second.second;
	}
	return a.second.first < b.second.first;
}

bool compare_for_answer(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.first < b.first;
}

int main() {
	vector<int> students;
	vector<pair<int, pair<int, int>>> photos; // <후보자 번호, 추천 횟수, 들어온 순서>
	int photo_size, rcmd_cnt;
	cin >> photo_size >> rcmd_cnt;
	for (int i = 0; i < rcmd_cnt; i++) {
		int num;
		cin >> num;
		students.push_back(num);
	}

	for (int i = 0; i < students.size(); i++) {
		bool is_exist = false;
		// 이미 추천받은 학생이면 추천 횟수만 증가
		for(int j = 0; j < photos.size(); j++) {
			if (students[i] == photos[j].first) {
				photos[j].second.first++;
				is_exist = true;
				break;
			}
		}
		// 처음 추천받는 학생인 경우 photo에 추가
		if (!is_exist) {
			if (photos.size() >= photo_size) { // 사진이 다 찼으면
				sort(photos.begin(), photos.end(), compare);
				photos.erase(photos.begin()); // 가장 우선순위 낮은 학생 삭제
			}
			photos.push_back({students[i], {1, i}});	
		}
	}

	// 정답 출력
	sort(photos.begin(), photos.end(), compare_for_answer);
	for(int i = 0; i < photos.size(); i++)
		cout << photos[i].first << ' ';

}