#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp_plays(pair<string, int>& a, pair<string, int>& b){
	return a.second > b.second;
}

bool cmp_song_plays(pair<int, int>& a, pair<int, int> &b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> genre_plays;
    
    // [장르 : 장르재생횟수] 맵
    for(int i = 0; i < genres.size(); i++) {
        genre_plays[genres[i]] += plays[i];
    }
    vector<pair<string, int>> vec_plays(genre_plays.begin(), genre_plays.end());
    sort(vec_plays.begin(), vec_plays.end(), cmp_plays);

    for(int i = 0; i < min(static_cast<size_t>(2), vec_plays.size()); i++) {
        int max1 = 0, max2=0;
        for(int j = 0; j < genres.size(); j++) {
            if (genres[j] == vec_plays[i].first) {
                int previous_max1 = max1;
                max1 = max(max1, plays[j]);
                max2 = max1 == plays[j] ? previous_max1 : max2;
            }
        }
        if (max1) answer.push_back(max1);
        if (max2) answer.push_back(max2);
    }
    
    return answer;
}