class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> mapNums;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
        mapNums[nums[i]] = mapNums[nums[i]] + 1;
        if ( 2 * mapNums[nums[i]] >= size) {
            return nums[i];
            }
        }
    }
};