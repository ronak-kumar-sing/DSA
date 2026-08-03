class Solution {

    List<String> ans = new ArrayList<>();

    private final String[] map;

    Solution(){
        map = new String[]{"" ,"" ,"abc" , "def", "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz" };
    }

    public void helper(String digits , int idx , String curr){
        if(curr.length() == digits.length()){
            ans.add(curr);
            return;
        }

        String val = map[digits.charAt(idx) - '0'];

        for(int i = 0 ; i < val.length(); i++){
            helper(digits , idx + 1 , curr + val.charAt(i));
        }

        
    }




    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0) return ans;

        helper(digits , 0 , new String());


        return ans;
    }
}