/*
 * Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
*/

function findMedianSortedArrays(nums1: number[], nums2: number[]): number {
    let combined = []

    let next1 = nums1.shift()
    let next2 = nums2.shift()

    while (next1 !== undefined && next2 !== undefined) {
        if (next1 < next2) {
            combined.push(next1)
            next1 = nums1.shift()
        } else {
            combined.push(next2)
            next2 = nums2.shift()
        }
    }

    while (next1 !== undefined) {
        combined.push(next1)
        next1 = nums1.shift()
    }

    while (next2 !== undefined) {
        combined.push(next2)
        next2 = nums2.shift()
    }

    if (combined.length % 2 === 0) {
        const left = (combined.length / 2) - 1
        const right = left + 1
        return (combined[left] + combined[right]) / 2
    } else {
        const index = Math.floor(combined.length / 2)
        return combined[index]
    }
};


/*
 * Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
 *
 * This is an alternate version that doesn't merge the arrays, on LeetCode they had about the same runtime, but this one uses less memory and would go slightly faster.
*/

function findMedianSortedArrays1(nums1: number[], nums2: number[]): number {
    let size = nums1.length + nums2.length

    const isEven = size % 2 === 0

    size = isEven ? (size / 2) - 1 : Math.floor(size/2)

    const getNextNum = () => {
        if (nums1.length > 0 && nums2.length > 0 ) {
            return nums1[0] < nums2[0] ? nums1.shift() : nums2.shift()
        }
        if (nums1.length > 0) {
            return nums1.shift()
        }
        if (nums2.length > 0) {
            return nums2.shift()
        }
    }

    let next1 = getNextNum()
    let next2 = getNextNum()

    while (size > -1) {
        if (size === 0) return !isEven ? next1 : (next1 + next2) / 2
        --size
        next1 = next2
        next2 = getNextNum()
    }
};
