const words = {
    zero : 0, 
    one : 1,
    two : 2,
    three : 3,
    four : 4,
    five : 5,
    six : 6,
    seven : 7,
    eight : 8,
    nine : 9,
}

function solution(s) {
    var answer = '';
    var i = 0;
    while(s[i]) {
        if (!isNaN(s[i])) {
            answer += s[i];
            i++;
        }
        else {
            var alpha = '';
            for(; isNaN(s[i]); i++) {
                alpha += s[i];
                if (alpha in words) {
                    answer += words[alpha];
                    i++;
                    break;
                }
            }
        }
    }
    return parseInt(answer);
}