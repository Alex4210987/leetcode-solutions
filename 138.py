# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: 'Optional[Node]') -> 'Optional[Node]':
        # O(n) time, O(n) space
        if not head:
            return None
        # copy nodes
        current = head
        while current:
            new_node = Node(current.val)
            new_node.next = current.next
            current.next = new_node
            current = new_node.next
        # copy random pointers
        current = head
        while current:
            if current.random:
                current.next.random = current.random.next
            current = current.next.next
        # split lists
        current = head
        new_head = head.next
        while current:
            new_node = current.next
            current.next = new_node.next
            if new_node.next:
                new_node.next = new_node.next.next
            current = current.next
        return new_head