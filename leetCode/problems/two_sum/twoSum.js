/**
 * Thus function will find two elements in the array whose sum will be equal to target.
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
// let global_var;
// var twoSum = function (nums, target) {
//   let i,
//     j,
//     arr = [];
//   let k;
//   for (i = 0; i < nums.length; i++) {
//     console.log("i value", i);
//     for (k = i + 1; k < nums.length; k++) {
//       let complement = target - nums[i];
//       if (complement === nums[k]) {
//         arr.push(i);
//         arr.push(k);
//         return arr;
//       }
//     }
//   }
// };

const twoSum = (nums = [1, 2, 3], target = 5) => {
  let hash = {},
    i;
  for (i = 0; i < nums.length; i++) {
    let n = nums[i];
    if (hash[target - n] !== undefined) {
      return [i, hash[target - n]];
    }
  }
  return [];
};
