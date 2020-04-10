/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
    if(nums.length <= 2)
        return helper(nums);
    return Math.max(helper(nums.slice(1)),helper(nums.slice(0,nums.length-1)));
};
var helper = function(nums){
    if(!nums.length) return 0;
    var depth = [];
    depth[0] = nums[0];
    depth[1] = Math.max(nums[0],nums[1]);
    for(var i=2 ;i <nums.length;i ++){
        depth[i] = Math.max(nums[i] + depth[i-2],depth[i-1]);
    };
    return depth[nums.length-1];
}