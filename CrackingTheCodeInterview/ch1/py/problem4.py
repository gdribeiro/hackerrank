#!/usr/bin/python3

import unittest


# This solution uses a dictinary(a.k.a. hash table) to count the characters in the string
# And then compare them, if they are equal they are permutations of each other
# Runtime complesity is O(n) and space complexity is O(n) due to the hadh table


def palindromeCheck(stringA, stringB):
    myHash = dict()
    for s in stringA, stringB:
        for i in s:
            myHash[s] = dict()
            if i not in myHash[s].keys():
                myHash[s][i] = 1
            else:
                myHash[s][i] += 1
    
    for key in myHash[stringA].keys():
        if myHash[stringB][key] != myHash[stringA][key]:
            return False
    return True


class MyTest(unittest.TestCase):
    def setUp(self):
            self.stringA ='hello world'
            self.stringB = 'oleh rowld'
    def test_palindromeCheck(self):
        result = palindromeCheck(self.stringA, self.stringB)
        self.assertTrue(result)
        

if __name__ == "__main__":
    unittest.main()