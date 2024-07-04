function solution(s, n) {
    var answer = '';
    for(let i = 0; i < s.length; i++) {
        if (s[i] == ' ') answer += ' ';
        else if ('a' <= s[i] && s[i] <= 'z') {
            let newCode = s[i].charCodeAt() + n;
            if (newCode > 'z'.charCodeAt())
                newCode = newCode - 26;
            answer += String.fromCharCode(newCode);
        }
        else if ('A' <= s[i] && s[i] <= 'Z') {
            let newCode = s[i].charCodeAt() + n;
            if (newCode > 'Z'.charCodeAt())
                newCode = newCode - 26;
            answer += String.fromCharCode(newCode);
        }
    }
    return answer;
}