/**
 * After reviewing the other solutions I realized most faster solutions were merging all the lists into
 * an array, using the built in sort function, then converting it back to a LL. In the future I'd probably
 * try and do something similar. Why not take advantage of the already optimized sort function that's
 * built in, instead of rolling my own. It'd be easier to maintain.
 */

/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function mergeKLists(lists: Array<ListNode | null>): ListNode | null {
    let head = null
    let tail = null
    while (lists.length > 0) {
        let min = null
        let index = -1
        lists.forEach((currentNode, i) => {
            if (currentNode !== null) {
                if (min === null) {
                    min = currentNode.val
                    index = i
                } else if (currentNode.val < min) {
                    min = currentNode.val
                    index = i
                }
            }
        })
        
        if (min !== null) {
            if (head === null) {
                head = new ListNode(min)
                tail = head

                clearLastMin(lists, index)
            } else {
                tail.next = new ListNode(min)
                tail = tail.next

                clearLastMin(lists, index)
            }
        } else {
            lists = []
        }
    }

    return head

};

function clearLastMin(lists: Array<ListNode | null>, i: number) {
    if (lists[i] !== null) {
        lists[i] = lists[i].next
        if (lists[i] === null) {
            lists.splice(i, 1)
        }
    } else {
        lists.splice(i, 1)
    }
}
