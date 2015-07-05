class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> result{0,0};

		int max = abs(2 * nums[0] - target) / 2;
		for (int i = 1; i < nums.size(); ++i)
		{
			int tmp = abs(2 * nums[i] - target) / 2;
			if (tmp > max) max = tmp;
		}
		int* hash_array = new int[max + 1];
		int* tmp_index = new int[max + 1];
		memset(hash_array, -1, sizeof(int) * (max + 1));
		memset(tmp_index, -1, sizeof(int) * (max + 1));

		int result_index = 0;
		int i = 0;
		for (; i < nums.size(); ++i)
		{
			int index = abs(2 * nums[i] - target) / 2;
			if (hash_array[index] == -1)
			{
				hash_array[index] = nums[i];
				tmp_index[index] = i;
			}
			else
			{
				if (nums[i] + hash_array[index] == target)
				{
					int tmp = tmp_index[index];
					if (tmp < i)
					{
						result[0] = tmp + 1;
						result[1] = i + 1;
					}
					else
					{
						result[0] = i + 1;
						result[1] = tmp + 1;
					}
					break;
				}
			}
		}
		return result;
	}
};