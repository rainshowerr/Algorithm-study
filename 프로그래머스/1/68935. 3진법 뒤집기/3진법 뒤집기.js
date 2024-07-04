function solution(n) {
    var ternary = n.toString(3).split('').reverse().join('');
    return parseInt(ternary, 3);
}

// 숫자 -> 진법 문자열 : toString
// 진법 문자열 -> 숫자 : parseInt