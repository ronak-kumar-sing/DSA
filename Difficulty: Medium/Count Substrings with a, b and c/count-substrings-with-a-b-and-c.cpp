class Solution {
	public:
	int countSubstring(string &s) {
		// Code here
		int hash_table[3] = {0};
		int n = s.size();
		int cnt = 0 ;
		int start = 0;
		for (int end = 0; end < n ; end++) {
			hash_table[s[end] - 'a']++;
			while (hash_table[0] && hash_table[1] && hash_table[2]) {
				cnt += n - end;
				hash_table[s[start] - 'a']--;
				start++;
			}
		}
		return cnt;
		
	}
};
