class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            //new index�����ڲ����ö���������������е�������������±�Ҳ���Ա�ʾһ��״̬
            int m = abs(nums[i]) - 1;
            //�����ż�¼���ֵ�ֵ��������ʾ�Ѿ����ֹ�������δ����
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