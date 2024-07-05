function solution(answers) {
    var answer = [];
    let score = [0, 0, 0];
    const one = [1, 2, 3, 4, 5];
    const two = [2, 1, 2, 3, 2, 4, 2, 5];
    const thr = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5];
    for(let i = 0; i < answers.length; i++) {
        if (one[i % 5] == answers[i]) score[0]++;
        if (two[i % 8] == answers[i]) score[1]++;
        if (thr[i % 10] == answers[i]) score[2]++;
    }
    max = Math.max(...score);
    for(let i = 0; i < score.length; i++) {
        if (score[i] === max)
            answer.push(i + 1);
    }
    return answer;
}