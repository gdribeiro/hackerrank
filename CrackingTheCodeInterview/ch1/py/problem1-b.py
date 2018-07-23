#!/usr/bin/python3

# This answer uses quichsort with a tweak to maybe speed up the process
# to detect if there are duplicate characters in the array.
# First the array is sorted with quicksort, where is can detect sometimes if
# there are duplicates when the pivot and the element being tested are equal
# In this case it breakes down the sorting and jumps to linear comparison
# It is not much, but is avoids unnecessary work.


def quicksort(string):
    less = []
    equal = []
    greater = []

    if len(string) > 1:

        pivot = string[0]
        for i in string[1:]:
            print(i)
            if i < pivot:
                less.append(i)
            elif i > pivot:
                greater.append(i)
            else:
                # Since They are equal, just return them and stop this flow of recursion
                return [pivot, i]
        return quicksort(less) + [pivot] + quicksort(greater)
    else:
        return string

def isUnique(string):
    for i in range(len(string)-1): 
        if string[i] == string[i+1]:
            return False
    return True


if __name__ == "__main__":

    s = quicksort('asdfghjklqwerzxcv')
    d = isUnique(s)
    print(s, d)