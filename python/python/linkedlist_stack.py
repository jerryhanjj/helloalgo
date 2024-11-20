from typing import Union

class ListNode:
    """
    链表节点类
    """
    def __init__(self, val:int):
        self.val: int = val
        self.next: Union[ListNode, None] = None


class LinkedListStack:
    """
    基于链表实现的栈
    """
    def __init__(self, val:int):
        self._peek: Union[ListNode, None] = None
        self._size: int = 0
