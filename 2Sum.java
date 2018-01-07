class Solution {
    public int[] twoSum(int[] nums, int target) {
        int cnt = nums.length;
        int[] result = new int[2];
        for(int i=0; i<cnt; i++) {
            for(int j=i+1; j<cnt; j++) {
                if(nums[i]+nums[j] == target) {
                    result[0] = i;
                    result[1] = j;
                    return result;
                }
                continue;
            }
            continue;
        }
        return result;
    }
    public static void main(String []args){
        Solution solution = new Solution();
        int[] nums = {3,2,4};
        int target = 6;
        solution.twoSum(nums,target);
    }
}