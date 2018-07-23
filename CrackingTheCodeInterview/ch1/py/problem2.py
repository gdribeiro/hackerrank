#!/usr/bin/python3

# This answer uses a hash to count the elements in each string,
# if the number of each element is equal, then the strings are
# permutattions of each other.
# The solutions iterates through each string once to count the
# elements and then again to compare the counts.
# it's obvious they have to be of same size.


def coutCharacters(string):
    hashTable = dict()
    for i in string:
        if i in hashTable.keys():
            hashTable[i] += 1
        else:
            hashTable[i] = 1

    return hashTable

def compareHashs(hashA, hashB):
    for i in hashA:
        if i in hashB.keys():
            if hashA[i] == hashB[i]:
                pass
            else:
                return False
        else:
            return False
    return True

if __name__ == "__main__":
    stringA = 'hello'
    stringB = 'olleh'

    hashA = coutCharacters(stringA)
    hashB = coutCharacters(stringB)

    arePermutations = compareHashs(hashA, hashB)
    print(arePermutations)