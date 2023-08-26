# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def isPalindrome(self, head) -> bool:#reverse and compare
        if not head:
            return True
        reversed_head=self.reverse(head)
        while head and reversed_head:
            if head.val!=reversed_head.val:
                return False
            head=head.next
            reversed_head=reversed_head.next
        return True
    def reverse(self,head):#do not modify the original list
        if not head:
            return None
        new_head=ListNode(head.val)
        head=head.next
        while head:
            new_head=ListNode(head.val,new_head)
            head=head.next
        return new_head