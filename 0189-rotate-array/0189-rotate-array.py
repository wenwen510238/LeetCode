class Solution:
    def reverse(self, nums: List[int], left: int, right: int):
        while left<right:
            nums[left], nums[right] = nums[right], nums[left]
            left += 1
            right -= 1
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        k %= len(nums)
        n = len(nums)
        self.reverse(nums, 0, n-1)
        self.reverse(nums, 0, k-1)
        self.reverse(nums, k, n-1)
    
   

