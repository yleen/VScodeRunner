# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        curr = head
        prev = None
        while curr != None:
            nextNode = curr.next
            curr.next = prev
            prev = curr
            curr = nextNode

        return prev


class Solution2:
    def reverseList(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        newhead=self.reverseList(head.next)
        head.next.next=head
        head.next=None

        return newhead  