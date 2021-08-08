/**
Problem description: A peak element is an element that is greater than its neighbors. 
Given an input array nums, where nums[i] ≠ nums[i+1], find a peak element and return its index.
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
*/

/**
 * @param {number[]} nums
 * @return {number}
 
 
 ----------------ITERATION-1:----------------
 L=0, R=6
 i=(6-0)/2=3 
        v(m)
 [1,2,1,3,5,6,4]
  ^L          ^R
 |-------------|
 3>1 [Thus peak will be on the right side]
 ----------------ITERATION-2:----------------
 L=i=3, R=6
 i=(6-3)/2+L=3+1=4 [The reason we add 'left' is to the shrunk the array]
          v(m)
 [1,2,1,3,5,6,4]
        ^L    ^R
 ----------------ITERATION-3:---------------- 
 5>3 [Thus peak will be on the right side]
 L=i=4 R=6
 i=(4-6)/2+L=1+4=5
            v(m)
 [1,2,1,3,5,6,4]
          ^L  ^R
 ----------------ITERATION-4:---------------- 
 6>5 [Thus peak will be on the right side]
 L=i=5 R=6
 i=([6-5]/2)+L=5
            v(m)
 [1,2,1,3,5,6,4]
            ^L^R
----------------ITERATION-5:----------------             
 6>4 (false)[Thus peak will be on the left side]
 right=i
 
 */
var findPeakElement = function(nums) {
    let left=0, right=nums.length-1;
    
    while(left<right){
        let i=left + Math.floor((right-left)/2)    
        if(nums[i]<nums[i+1]){
            left=i+1;
        }else{
            right=i
        }
        
    }
    
    return left;    
};