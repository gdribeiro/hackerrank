#!/usr/bin/python3

# This solution counts the number of total spaces in the string
# and the number of consecutive spaces. Then adds the necessary
# extra spaces to the string and starts to make the replacements
# The time complexity is O(n), since it needs to check each element
# Altough it works fine for most cases, there is a restriction.
# The number of spaces has alrady in the string has to be less
# than the number of characters to be added
# Space complesity is O(1) since all the replacemests are done in place


def urlFy(string, length):
    spaceCount = 0
    extraSpace = 0

    for i in range(len(string)):
        if string[i] == ' ' and string[i-1] != ' ':
            spaceCount += 1
        if string[i] == ' ':
            extraSpace += 1
    
    if (spaceCount*3 - extraSpace) > 0:
        for i in range(spaceCount*3 - extraSpace):
            string.append('-')

    newIndex = spaceCount*3 - extraSpace
    for i in reversed(range(length)):
        if string[i] == ' ' and string[i-1] == ' ':
            newIndex += 1
            continue
        elif string[i] == ' ':
            string[i + newIndex] = '0'
            string[i + newIndex - 1] = '2'
            string[i + newIndex - 2] = '%'
            newIndex -= 2
        elif string[i] != ' ':
            string[i + newIndex] = string[i]
    return string


if __name__ == "__main__":

    url = list('Hello, Mr.   Robot!')
    length = len(url)
    string = urlFy(url, length)
    print(string)
