/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */



var merge = function(nums1, m, nums2, n) {
    // Since they gave room at the end of the array; thereby we start from the end
    // set the pointers at the last element in the array
    // NOTE: the nums1 array will always be larger than nums2
    // compare the pointers and the largest value will be put at the nums1--> pointer position
    // iterate the nums1 array
    
    --m;
    --n;
    let i = nums1.length-1
    /*                
                   v(i)
        [1,2,3,0,0,0]
             ^(m)
        [2,5,6]
             ^(n)
    */
    while(0<=i){
        if(m<0){
            nums1[i]=nums2[n];
            n--;
        }else if(n<0){
            nums1[i]=nums1[m];
            m--;
        }else{
            if(nums1[m]>nums2[n]){
                nums1[i] = nums1[m]
                m--;
            }else{
                nums1[i] = nums2[n];
                n--;
            }
        }
        i--;
    }
};