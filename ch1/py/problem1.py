#!/bin/python3

# This answer uses a hash table to count the characters in the string
# if there is one character with count greather than 1 return False
# the runtime is O(n) because it visits each character once to insert in the hash
# There is extra memory being used for the new data structure


def isUnique(string):
    charachters = dict()
    for i in string:
        if i not in charachters.keys():
            charachters[i] = 1
        else:
            charachters[i] += 1
        if charachters[i] > 1:
            return False

    return True

if __name__ == "__main__":

    s = 'hello'
    d = isUnique(s)
    print(d)