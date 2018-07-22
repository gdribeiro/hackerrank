#!/usr/bin/python3


"""

3.1 
Three in One: Describe how you could use a single array to implement three stacks.
Hints: #2, #72, #38, #58

"""

""" 

Assuming that any stack is just as likely to have elements added or removed from it.
The array can be divided in 3 and 3 blocks, where there is a shift of 3 to the next element of the stack
The downside is that each time one of the stacks grows to more than 1/3 of the array's size, it would have
to be extended. Leading to a O(n) space complexity and runtime complexity of O(1) just as in the resizable
array scenario.
Now, imagine the code. I won't write it now...

"""