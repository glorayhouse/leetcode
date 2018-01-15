class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        if (size <= 0) return 0;
        int cnt = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) {
                cnt++;
            } else {
                nums[i-cnt] = nums[i];
            } 
        }
        return size-cnt;
    }
};