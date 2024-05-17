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
