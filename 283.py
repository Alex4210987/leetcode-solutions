class Solution:
    def moveZeroes(self, nums: List[int]) -> None:

        if not nums:
            return
        
        slow = 0
        for fast in range(len(nums)):
            if nums[fast] != 0:
                nums[slow] = nums[fast]
                slow += 1
        
        for i in range(slow, len(nums)):
            nums[i] = 0 