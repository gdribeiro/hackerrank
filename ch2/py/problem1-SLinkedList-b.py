#!/usr/bin/python3

import unittest

# 2.1
# Remove Dups: Write code to remove duplicates from an unsorted linked list.
# How would you solve this problem if a temporary buffer is not allowed?
# Hints: #9, #40
#9. 2.1 Have you tried a hash table? You should be able to do this in a single pass of the linkedlist.
#40. 2.1 Without extra space, you'll need (N2) time. Try using two pointers, where the secondone searches ahead of the first one.


class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
    def getVal(self):
        return self.val
    def getNext(self):
        return self.next
    def setNext(self, next):
        self.next = next

class SLinkedList:
    def __init__(self):
        self.head = None
    def getHeadVal(self):
        if self.head is not None:
            return self.head.getVal()
        else:
            return None
    def getTail(self):
        current = self.head
        while current.getNext():
            current = current.getNext()
        return current
    def append(self, val):
        newNode = Node(val)
        if self.head is None:
            self.head = Node(val)
        else:
            current = self.head
            while(current.getNext()):
                current = current.getNext()
            current.setNext(newNode)
    def preppend(self, val):
        newNode = Node(val)
        newNode.setNext(self.head)
        self.head = newNode
    def deleteHead(self):
        if self.head is not None:
            self.head = self.head.getNext()
            return True
        return False
    def deleteFirstByVal(self, val):
        current = self.head
        if self.head.getVal() == val:
            self.deleteHead()
            return True
        while current.getNext():
            if current.getNext().getVal() == val:
                current.setNext(current.getNext().getNext())
                return True
            current = current.getNext()
        return False
    def getListSize(self):
        count = 0
        current = self.head
        while True:
            if current is None:
                return count
            else:
                count += 1
                current = current.getNext()
    def printList(self):
        current = self.head
        if self.head is None:
            return
        while True:
            print(current.getVal())
            current = current.getNext()
            if current is None:
                break
    def deleteDuplicates(self):
        hashT = dict()
        current = self.head
        if self.head is None:
            return
        else:
            hashT[self.head.getVal()] = 1
        while True:
            if current.getNext() is not None:
                if current.getNext().getVal() in hashT.keys():
                    newNext = current.getNext().getNext()
                    current.setNext(newNext)
                else:
                    hashT[current.getNext().getVal()] = 1
                    current = current.getNext()
            else:
                return

class MyTest(unittest.TestCase):
    def setUp(self):
        self.head = SLinkedList()        
    def test_appendHeadTest(self):
        self.head.append(1)
        self.assertEqual(self.head.getHeadVal(), 1)
    def test_appendTest(self):
        self.head.append(1)
        self.head.append(2)
        self.assertEqual(self.head.getTail().getVal(), 2)
        self.head.append(3)
        self.assertEqual(self.head.getTail().getVal(), 3)
        self.head.append(4)
        self.assertEqual(self.head.getTail().getVal(), 4)
        self.head.append(5)
        self.assertEqual(self.head.getTail().getVal(), 5)
        self.head.append(6)
        self.assertEqual(self.head.getTail().getVal(), 6)
        self.assertEqual(self.head.getHeadVal(), 1)
    def test_deteHeadTest(self):
        self.head.append(1)
        self.head.append(2)
        self.head.append(3)
        self.head.deleteHead()
        self.assertEqual(self.head.getHeadVal(), 2)
        self.head.deleteHead()
        self.assertEqual(self.head.getHeadVal(), 3)
        self.head.deleteHead()
        self.assertIsNone(self.head.getHeadVal())
        self.head.deleteHead()
        self.assertIsNone(self.head.getHeadVal())
    def test_preppendTest(self):
        self.head.append(1)
        self.head.append(2)
        self.head.append(3)
        self.head.preppend(10)
        self.assertEqual(self.head.getHeadVal(), 10)
    def test_deleteFirstByValTest(self):
        self.head.append(3)
        self.head.append(1)
        self.head.append(3)
        self.head.deleteFirstByVal(3)
        self.assertEqual(self.head.getTail().getVal(), 3)
        self.assertEqual(self.head.getHeadVal(), 1)

    def test_getListSize(self):
        self.head.append(1)
        self.head.append(2)
        self.head.append(3)
        self.assertEqual(self.head.getListSize(), 3)

    def test_deleteDuplicates(self):
        self.head.append(1)
        self.head.append(2)
        self.head.append(3)
        self.head.append(4)
        self.head.append(3)
        self.head.append(1)
        self.head.append(3)
        self.head.deleteDuplicates()
        self.assertEqual(self.head.getHeadVal(), 1)
        self.assertEqual(self.head.getTail().getVal(), 4)
        self.assertEqual(self.head.getListSize(), 4)
        self.head.printList()


if __name__ == "__main__":
    unittest.main()