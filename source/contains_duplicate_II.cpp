class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> hash_array;
        
        for(int i = 0; i < nums.size(); ++i){
            hash_array[nums[i]].push_back(i);
        }
        
        map<int, vector<int>>::iterator it;
        
        for(it = hash_array.begin(); it != hash_array.end(); ++it){
            vector<int>& tmp = it->second;
            if(tmp.size() > 1){
                int dif = 0;
                for(int i = 1; i < tmp.size(); ++i){
                    if(tmp[i] - tmp[i - 1] <= k)
                        return true;
                }
            }
        }
        
        return false;
    }
};