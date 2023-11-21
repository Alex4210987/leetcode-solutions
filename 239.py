from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if not nums:
            return nums
        
        ans = []
        window = deque()  # 双端队列，用于存储窗口内元素的索引
        
        # 初始化窗口
        for i in range(k):
            while window and nums[i] >= nums[window[-1]]:
                window.pop()
            window.append(i)
        
        # 处理剩余的窗口
        for i in range(k, len(nums)):
            ans.append(nums[window[0]])  # 当前窗口的最大值即为窗口队列的第一个元素
            
            # 移除窗口中已经不在当前窗口范围内的元素
            while window and window[0] <= i - k:
                window.popleft()
            
            # 保持窗口内元素的单调递减顺序
            while window and nums[i] >= nums[window[-1]]:
                window.pop()
            
            window.append(i)
        
        ans.append(nums[window[0]])  # 处理最后一个窗口的最大值
        
        return ans
