#You must write an algorithm that runs in O(n) time.
#Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)#remove duplicates
        longest = 0
        for num in nums:
            if num - 1 not in nums:
                current = num
                current_length = 1
                while current + 1 in nums:
                    current += 1
                    current_length += 1
                longest = max(longest, current_length)
        return longest                