class Solution {
public:
	string longestPalindrome(string s) {
		int new_size = s.length * 2 + 2;
		char* new_str = new char[new_size];
		new_str[0] = '$';
		for (int i = 0; i < s.length; ++i){
			new_str[2 * i + 1] = '#';
			new_str[2 * i + 2] = s[i];
		}
		new_str[new_size - 1] = '#';

		int* p = new int[new_size];

		int id = 0, maxid = 0, ans = 1;
		for (int i = 0; i < new_size; ++i){
			if (maxid > i){
				p[i] = min(p[2 * id - 1], maxid - i);
			}
			else{
				p[i] = 1;
			}

			while (new_str[i + p[i]] == new_str[i - p[i]]) p[i]++;

			if (i + p[i] > maxid) { id = i; maxid = i + p[i]; }

			if (ans < p[i]) ans = p[i];
		}



		char* str = new char[ans + 1];

		for (int i = id, j = 0; i < id + ans; ++i){
			if (new_str[i] != '#'){
				str[j] = new_str[i];
				j++;
			}
		}

		str[ans - 1] = '\0';

	}
};
