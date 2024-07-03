 class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> ump;
        int n = nums.size();
        vector<int> final;
        for(int i = 0; i < n; i++){
            auto k = ump.find(nums[i]);
            if(k == ump.end()){
                ump.insert({nums[i], 1});
            }
            else{
                k->second += 1;
            }
        }
        for(auto it = ump.begin(); it != ump.end(); it++){
            if(it->second > n/3){
                final.push_back(it->first);
            }
        }
        return final;
    }
};