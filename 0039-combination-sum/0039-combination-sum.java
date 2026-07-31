class Solution {
    List<List<Integer>> result = new ArrayList<>();

    public void helper(int[] arr, int target, int idx, ArrayList<Integer> list, int sum) {

        if (sum == target) {
            result.add(new ArrayList(list));
            return;
        }
        
        if(arr.length == idx) return;

        if (sum > target)
            return;

        list.add(arr[idx]);

        helper(arr, target, idx, list, sum + arr[idx]);

        list.remove(list.size() - 1);

        helper(arr, target, idx + 1, list , sum );

    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        helper(candidates, target, 0, new ArrayList<>(), 0);
        return result;
    }
}