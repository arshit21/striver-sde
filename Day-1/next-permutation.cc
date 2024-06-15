class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        for(int i = size-1; i > 0; i--){
            if(nums[i] > nums[i-1]){
                int prevI = i-1;
                int prevVal = nums[i-1];
                int index;
                sort(nums.begin()+prevI, nums.end());
                for(int j = prevI; j < size-1; j++){
                    if(nums[j] == prevVal && nums[j+1] > nums[j]){
                        index = j+1;
                    }
                }

                int a = nums[prevI];
                nums[prevI] = nums[index];
                nums[index] = a;

                sort(nums.begin()+i, nums.end());
                return;
            }
        }

        sort(nums.begin(), nums.end());
        return;


    }
};