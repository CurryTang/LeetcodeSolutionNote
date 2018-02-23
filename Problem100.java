/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return preOrderTheSame(p, q) && postOrderTheSame(p, q);
        
    }
    
    public static boolean preOrderTheSame(TreeNode p, TreeNode q){
        if (p == null && q != null){
            return false;
        } else if (p != null && q == null){
            return false;
        } else if (p == null && q == null){
            return true;
        } else {
            boolean same = (p.val == q.val) ? (true) : (false);
            boolean left = preOrderTheSame(p.left, q.left);
            boolean right = preOrderTheSame(p.right, q.right);
            return same && left && right;
        }
    }
    
    public static boolean postOrderTheSame(TreeNode p, TreeNode q){
        if (p == null && q != null){
            return false;
        } else if (p != null && q == null){
            return false;
        } else if (p == null && q == null){
            return true;
        } else {
            boolean left = postOrderTheSame(p.left, q.left);
            boolean right = postOrderTheSame(p.right, q.right);
            boolean same = (p.val == q.val) ? (true) : (false);
            return same && left && right;
        }
    }
}
