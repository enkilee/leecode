class Solution {
    public int findRepeatNumber(int[] nums) {
		for(int i = 0;i<nums.length; i++) {
			while(nums[i] != i) {
				//索引i上的值如果和桶号为nums[i]上的值相等则出现重复值，直接返回；若没则进行交换
				if(nums[i] == nums[nums[i]])  
					return nums[i];
				swap(nums, i, nums[i]);
			}
		}
		//不能返回数值以免干扰结果，故抛错处理
		throw new IllegalArgumentException("没有找到重复数字");
	}
	private static void swap(int[] nums, int pre, int post) {
        int temp = nums[pre];
        nums[pre] = nums[post];
        nums[post] = temp;
    } 
}
