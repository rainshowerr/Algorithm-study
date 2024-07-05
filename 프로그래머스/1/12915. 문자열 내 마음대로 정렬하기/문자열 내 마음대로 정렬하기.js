function solution(strings, n) {
    strings.sort();
    strings.sort((a, b) => a[n].charCodeAt() - b[n].charCodeAt());
    return strings;
}

// charCodeAt으로 아스키키드로 바꿔준다음 비교