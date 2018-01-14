class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //注意需要修改原数组元素，并返回非重复元素个数
        int size = nums.size();
        if (size <= 0) return 0;
        if (size == 1) return 1;
        //last表示最后一个不相等元素的下标
        int last = 1;
        for (int i = 1; i < size; i++) {
            if (nums[i] != nums[i-1]){
                nums[last] = nums[i];
                last++;
            }
        }
        return last;
    }
};