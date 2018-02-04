class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            //new index，由于不能用多余变量，考虑现有的条件，数组的下标也可以表示一种状态
            int m = abs(nums[i]) - 1;
            //正负号记录出现的值，负数表示已经出现过，正数未出现
            nums[m] = (nums[m] > 0) ? -nums[m] : nums[m];
        }
        vector<int> res;
        for (int i = 0; i < size; i++) {
            if (nums[i] > 0)
                res.push_back(i+1);
        }
        return res;
    }
};