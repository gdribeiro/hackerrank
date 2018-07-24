#!/usr/bin/python3

import unittest


# This solution uses a dictinary(a.k.a. hash table) to count the characters in the string
# And then compare them, if they are equal they are permutations of each other
# Runtime complesity is O(n) and space complexity is O(n) due to the hadh table
# This problem is very tricky with a weird description


def palindromeCheck(string):
    myHash = dict()
    oddCount = 0
    length = 0
    for char in string:
        if char.isalpha():
            if char not in myHash.keys():
                myHash[char] = 1
                oddCount += 1
            else:
                myHash[char] += 1
                if myHash[char] % 2:
                    oddCount += 1
                else:
                    oddCount -= 1
            length += 1
        
    if oddCount == 1 and length % 2 == 1:
        return True
    elif oddCount == 0 and length % 2 == 0:
        return True
    else:
        return False


class MyTest(unittest.TestCase):
    def setUp(self):
        self.data = [
        ('Tact Coa', True),
        ('jhsabckuj ahjsbckj', True),
        ('Able was I ere I saw Elba', True),
        ('So patient a nurse to nurse a patient so', False),
        ('Random Words', False),
        ('Not a Palindrome', False),
        ('no x in nixon', True),
        ('azAZ', True)]

    def test_palindromeCheck(self):
        for [test_string, expected] in self.data:
            # Have to ignore letter's case
            actual = palindromeCheck(test_string.lower())
            print(actual, expected)
            self.assertEqual(actual, expected)
        

if __name__ == "__main__":
    unittest.main()