// This answer uses a map<char, bool> to check if the character was
// already found in the string. If yes, return false for not unique
// characters in it, otherwise return true for unique characters in
// the string.
// the runtime complexity is O(n) because it visits each character
// once to insert in the hash
// There is extra memory being used for the new data structure

#include<iostream>
#include<cstdio>
#include<map>

using namespace std;

bool isUnique(std::string inString) {
    std::map<char, bool> letters;
    for(std::string::iterator i=inString.begin(); i != inString.end(); i++)
    {
        if (letters[*i]) {
            return false;
        } else {
            letters[*i] = true;
        }   
    }
    return true;
}

int main() {
    std::string inString;
    std::getline(std::cin, inString);
    bool answer = isUnique(inString);
    cout << answer << endl;

    return 0;
}