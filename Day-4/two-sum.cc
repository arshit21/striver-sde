class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> ump;
        vector<int> final;
        for(int i = 0; i < n; i++){
            int num = nums[i];
            int moreNeeded = target - num;
            if(ump.find(moreNeeded) != ump.end()){
                return {ump[moreNeeded], i};
            }
            ump[num] = i;
        }
        return {0};
    }
};