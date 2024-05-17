/**
 * Link: https://leetcode.com/problems/delete-leaves-with-a-given-value/
 * Definition for a binary tree node.
 * class TreeNode {
 *     val: number
 *     left: TreeNode | null
 *     right: TreeNode | null
 *     constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.left = (left===undefined ? null : left)
 *         this.right = (right===undefined ? null : right)
 *     }
 * }
 */

function removeLeafNodes(root: TreeNode | null, target: number): TreeNode | null {
    if (root.left) root.left = removeLeafNodes(root.left, target)

    if (root.right) root.right = removeLeafNodes(root.right, target)

    if (!root.left && !root.right) {
        if (root.val === target) {
            return null
        } else {
            return root
        }
    } else {
        return root
    }


};
