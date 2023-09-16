from statistics import median

from sortedcontainers import SortedList
class MedianFinder:

    def __init__(self):

        self.sorted_list=SortedList()
    def addNum(self, num: int) -> None:

        self.sorted_list.add(num)

    def findMedian(self) -> float:

        return median(self.sorted_list)

# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()