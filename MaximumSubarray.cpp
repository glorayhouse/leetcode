class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int preMax = nums[0];
        int curMax = nums[0];
        int size = nums.size();
        for (int i = 1; i < size; i++) {
            //�ж���ǰ��һ���ĵ�ʧ���Ӻ͵�ֵ�Ƚϴ��ǵ�ǰֵ�Ƚϴ�
            preMax = max(preMax+nums[i],nums[i]);
            //��ǰ������
            curMax = max(preMax, curMax);
        }
        return curMax;
    }
};