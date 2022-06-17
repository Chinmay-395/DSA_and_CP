/**
 * @param {number} x
 * @return {number}
 */

/* Solution-1 */
const reverse1 = (x) => {
  const limit = 2147483648;
  const k = x < 0 ? -1 : 1;
  const n = Number(String(Math.abs(x)).split("").reverse().join(""));
  return n > limit ? 0 : n * k;
};

/*Solution-2*/
var reverse2 = function (x) {
  var reverseN = 0;
  let n = x;
  var sign = n < 0;
  n = Math.abs(n);
  while (n) {
    reverseN = reverseN * 10 + (n % 10);
    n = Math.floor(n / 10);
  }
  return reverseN > 0x7fffffff ? 0 : sign ? -reverseN : reverseN;
};
console.log(reverse(-123));
console.log(reverse(1563847412));
