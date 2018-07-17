#!/bin/python3

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