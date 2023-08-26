class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        product = 0
        zero_count = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                zero_count += 1
                continue
            if product == 0:
                product = 1
            product *= nums[i]
        ans = []
        for i in range(len(nums)):
            if nums[i] == 0:
                if zero_count > 1:
                    ans.append(0)
                else:
                    ans.append(product)
            else:
                if zero_count > 0:
                    ans.append(0)
                else:
                    ans.append(product // nums[i])
        return ans
    