function makeBinaryMap(arr) {
    var map = new Array(arr.length).map(() => new Array(arr.length));
    for(let i = 0; i < arr.length; i++) {
        row = arr[i].toString(2);
        while (row.length != arr.length) {
            row = '0' + row;
        }
        map[i] = row;
    }
    return map;
}

function solution(n, arr1, arr2) {
    const map1 = makeBinaryMap(arr1);
    const map2 = makeBinaryMap(arr2);
    let res = new Array(n).fill(0).map(() => new Array(n).fill(' '));
    for(let i = 0; i < n; i++) {
        for (let j = 0; j < n; j++) {
            if (map1[i][j] === '1' || map2[i][j] === '1')
                res[i][j] = '#';
        }
        res[i] = res[i].join('');
    }
    return res;
}