class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int preMax = nums[0];
        int curMax = nums[0];
        int size = nums.size();
        for (int i = 1; i < size; i++) {
            //判断往前走一步的得失，加和的值比较大还是当前值比较大
            preMax = max(preMax+nums[i],nums[i]);
            //当前的最大和
            curMax = max(preMax, curMax);
        }
        return curMax;
    }
};