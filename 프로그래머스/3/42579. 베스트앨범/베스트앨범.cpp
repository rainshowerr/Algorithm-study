#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> global_plays;

bool cmp_genre_plays(pair<string, int>& a, pair<string, int>& b){
	return a.second > b.second;
}

bool cmp_song_plays(int& a, int& b) {
    if (global_plays[a] == global_plays[b])
        return a < b;
    return global_plays[a] > global_plays[b];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    global_plays = plays;
    vector<int> answer;
    map<string, int> genre_plays;
    map<string, vector<int>> genre_songs;
    
    // 맵 초기화
    for(int i = 0; i < genres.size(); i++) {
        genre_plays[genres[i]] += plays[i]; // {장르 : 장르재생횟수}
        genre_songs[genres[i]].push_back(i); // {장르 : [곡번호]}
    }
    
    // [{장르, 재생횟수}] 벡터에서 재생횟수 많은 순으로 장르 정렬
    vector<pair<string, int>> vec_genre_plays(genre_plays.begin(), genre_plays.end());
    sort(vec_genre_plays.begin(), vec_genre_plays.end(), cmp_genre_plays);
    
    // {장르: [곡]} 맵에서 재생횟수 많은 순으로 곡 정렬
    for(auto& genre : genre_songs) {
        sort(genre.second.begin(), genre.second.end(), cmp_song_plays);
    }
    
    for(auto& genre : vec_genre_plays) {
        for(int j = 0; j < min((unsigned long)2, genre_songs[genre.first].size()); j++) {
            answer.push_back(genre_songs[genre.first][j]);
        }
    }
    
    return answer;
}