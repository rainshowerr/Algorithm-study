function solution(s) {
    var answer = [];
    for(let i = 0; i < s.length; i++) {
        let cnt = 0;
        for(var j = i - 1; j >= 0; j--) {
            cnt++;
            if (s[i] === s[j])
                break;
        }
        if (j === -1)
            answer.push(-1);
        else
            answer.push(cnt);
    }
    return answer;
}