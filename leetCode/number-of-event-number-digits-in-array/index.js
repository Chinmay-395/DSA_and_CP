/**
 * @param {number[]} nums
 * @return {number}
 */

const numberOfDigits = (num) => {
  let count = 0;
  while (num / 10) {
    if (num >= 1 || num === 0) {
      num = num / 10;
      count += 1;
      console.log("=====>", count, num);
    } else {
      // console.log("rety",count)
      return count;
    }
  }
};

var findNumbers = function (nums) {
  let arr = [];
  nums.map((item, index) => {
    // find the number of digits in every item
    let x = numberOfDigits(item);
    console.log(x);
    if (x % 2 === 0) {
      arr.push(x);
    }
  });
  console.log("ARR", arr);
  return arr.length;
};
