function solution(d, budget) {
    var answer = 0;
    var sum = 0;
    d.sort((a, b) => a - b);
    for(let i = 0; i < d.length && sum + d[i] <= budget; i++) {
        sum += d[i];
        answer++;
    }
    return answer;
}