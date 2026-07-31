class Solution {
    List<List<Integer>> result = new ArrayList<>();

    public void helper(int[] arr, int target, int idx, ArrayList<Integer> list) {

        if (target == 0) {
            result.add(new ArrayList(list));
            return;
        }
        if (arr.length == idx) {
            return;
        }

        for (int i = idx; i < arr.length; i++) {

            if(i > idx && arr[i] == arr[i - 1]){
                continue;
            }
            if (arr[i] > target)
                break;

            list.add(arr[i]);
            helper(arr, target - arr[i], i + 1, list);
            list.remove(list.size() - 1);
        }

    }

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        helper(candidates, target, 0, new ArrayList<>());
        return result;
    }
}