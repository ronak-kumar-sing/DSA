class Solution {
    List<List<Integer>> result = new ArrayList<>();
    public void helper(int k , int n , ArrayList<Integer> list, int i){
        if(i > 10) return;
        if(list.size() == k){
            if(n == 0) result.add( new ArrayList(list));
            return;
        }

        list.add(i);

        helper(k , n - i , list , i + 1);

        list.remove(list.size() - 1);

        helper(k , n, list , i + 1);
    }
    public List<List<Integer>> combinationSum3(int k, int n) {
        helper(k , n , new ArrayList<>(), 1);

        return result;
    }
}