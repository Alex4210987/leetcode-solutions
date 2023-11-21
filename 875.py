class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
            if not piles:
                return 0
            
            left, right = 1, max(piles)
            while left < right:
                mid = left + (right - left) // 2
                
                if self.can_finish(piles, h, mid):
                    right = mid
                else:
                    left = mid + 1
            
            return left
    def can_finish(self, piles, h, speed):
        time = 0
        for pile in piles:
            time += (pile - 1) // speed + 1
        
        return time <= h