function solution(t, p) {
    var answer = 0;
    var len = p.length;
    for(let i = 0; i < t.length - len + 1; i++) {
        if (parseInt(t.substr(i, len)) <= parseInt(p))
            answer++;
    }
    return answer;
}