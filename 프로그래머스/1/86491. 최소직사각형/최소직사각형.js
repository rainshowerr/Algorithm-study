function solution(sizes) {
    var answer = 0;
    var wallet = [0, 0];
    for(let i = 0; i < sizes.length; i++) {
        if (sizes[i][0] < sizes[i][1])
            [sizes[i][0], sizes[i][1]] = [sizes[i][1], sizes[i][0]];
        if (sizes[i][0] > wallet[0])
            wallet[0] = sizes[i][0];
        if (sizes[i][1] > wallet[1])
            wallet[1] = sizes[i][1];
    }
    return wallet[0] * wallet[1];
}