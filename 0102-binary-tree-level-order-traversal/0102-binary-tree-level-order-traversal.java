/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();

        if(root == null) return result;

        Deque<TreeNode> q = new ArrayDeque<>();
        q.offer(root);

        while(!q.isEmpty()){
            int levelSize = q.size();
            List<Integer> list = new ArrayList<>();
            for(int i = 0 ; i < levelSize ; i++){
                TreeNode currNode = q.poll();
                list.add(currNode.val);
                if(currNode.left!= null){
                    q.offer(currNode.left);
                }
                
                if(currNode.right!=null){
                    q.offer(currNode.right);
                }
            }
            result.add(list);
        }

    return result;
}}