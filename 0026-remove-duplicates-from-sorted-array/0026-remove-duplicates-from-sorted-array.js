/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let k = 1;
    for(var i=0; i<nums.length; i++){
        if(nums[i] != nums[k-1]){
            nums[k] = nums[i]
            k++
        }
    }
    return k
};