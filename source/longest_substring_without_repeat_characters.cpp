class Solution {
public:
    int lengthOfLongestSubstring(string s) {
		if (s.size() <= 1) return s.size();
		int max_length = 0;
		bool *maps = (bool*)malloc(sizeof(bool) * 256);
		memset(maps, 0, sizeof(bool) * 256);
		int begin = 0;
		int end = 0;
		while (end < s.size())
		{
			if (!maps[s[end]])
			{
				maps[s[end]] = 1;
				max_length = max(max_length, (++end) - begin);
				if(max_length > (s.size() - begin)) break;
			}
			else
			{
				maps[s[begin++]] = 0;
			}
		}

		return max_length;

    }
};