function solution(participant, completion) {
    let parti = new Map();
    // 해시테이블 구현
    for(let i = 0; i < participant.length; i++) {
        if (!parti.has(participant[i]))
            parti.set(participant[i], 1);
        else
            parti.set(participant[i], parti.get(participant[i]) + 1);
    }
    // 삭제
    for(let i = 0; i < completion.length; i++) {
        if (parti.get(completion[i]) === 1)
            parti.delete(completion[i]);
        else
            parti.set(completion[i], parti.get(completion[i]) - 1);
    }
    // 출력
    for (let [key, value] of parti) {
            return key;
    }
}