class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:#without sorting
        def quickselect(l, r, k):
            if l == r:
                return nums[l]
            pivot = random.randint(l, r)
            pivot = partition(l, r, pivot)
            if k == pivot:
                return nums[k]
            elif k < pivot:
                return quickselect(l, pivot - 1, k)
            else:
                return quickselect(pivot + 1, r, k)
        def partition(l, r, pivot):
            pivot_val = nums[pivot]
            nums[pivot], nums[r] = nums[r], nums[pivot]
            store_index = l
            for i in range(l, r):
                if nums[i] < pivot_val:
                    nums[store_index], nums[i] = nums[i], nums[store_index]
                    store_index += 1
            nums[store_index], nums[r] = nums[r], nums[store_index]
            return store_index
        return quickselect(0, len(nums) - 1, len(nums) - k)
