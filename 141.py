#Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fastPointer=head
        while fastPointer and fastPointer.next:
            head=head.next
            fastPointer=fastPointer.next.next
            if head==fastPointer:
                return True
        return False
    