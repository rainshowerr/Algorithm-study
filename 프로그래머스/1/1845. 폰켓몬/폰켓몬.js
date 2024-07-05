function solution(nums) {
    var answer = 0;
    let set = new Set();
    for(let i = 0; i < nums.length; i++) {
        set.add(nums[i]);
    }
    return nums.length / 2 > set.size ? set.size : nums.length / 2;
}