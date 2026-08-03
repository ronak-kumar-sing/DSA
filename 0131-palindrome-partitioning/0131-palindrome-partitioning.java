class Solution {
    public List<List<String>> res = new ArrayList<>();

    public boolean isPalindrome(String s, int start, int end) {
        while (start <= end) {
            if (s.charAt(start++) != s.charAt(end--))
                return false;
        }
        return true;
    }

    public void helper(String s, int idx, List<String> path) {
        if (s.length() == idx) {
            res.add(new ArrayList(path));

            return;
        }

        for (int i = idx; i < s.length(); i++) {
            if (isPalindrome(s, idx, i)) {
                path.add(s.substring(idx, i + 1));
                helper(s, i + 1, path);
                path.remove(path.size() - 1);
            }
        }
    }

    public List<List<String>> partition(String s) {
        helper(s, 0, new ArrayList<>());
        return res;
    }
}