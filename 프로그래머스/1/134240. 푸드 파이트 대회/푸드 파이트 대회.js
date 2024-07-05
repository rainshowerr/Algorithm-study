function solution(food) {
    var answer = '';
    for(let i = 1; i < food.length; i++)
        answer += i.toString().repeat(food[i] / 2);
    revans = answer.split('').reverse().join('');
    answer += `0${revans}`;
    return answer;
}