class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //ע����Ҫ�޸�ԭ����Ԫ�أ������ط��ظ�Ԫ�ظ���
        int size = nums.size();
        if (size <= 0) return 0;
        if (size == 1) return 1;
        //last��ʾ���һ�������Ԫ�ص��±�
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