#include <iostream>
#include <cstdio>
#include <gtest/gtest.h>
#include <stack>
#include <string>


using namespace std;

string yes = "YES";
string no  = "NO";


string isBalanced(string s) {
    std::stack<char> bs;
    for(int i=0; i < s.size(); i++){
        switch(s[i]) {
            case '{':
            case '[':
            case '(':
                bs.push(s[i]);
                break;
            case '}':
            // In C++ you cant get the top() of a stack before testing if it is empty
            // If the stack is empty it will result in a error of which is not cought in compiling  time
            // Segmentation Fault (core dumped)
                if(bs.empty()) return "NO"; 
                if(bs.top() != '{') {
                    return "NO";
                }
                bs.pop();
                break;
            case ']':
                if(bs.empty()) return "NO";
                if(bs.top() != '[') {
                    return "NO";
                }
                bs.pop();
                break;
            case ')':
                if(bs.empty()) return "NO";
                if(bs.top() != '(') {
                    return "NO";
                }
                bs.pop();
                break;
        }
    }
    if(bs.empty()) return "YES";
    return "NO";
}

TEST(BalancedBrackets, no1){
    string s = "}][}}(}][))]";
    string answer = isBalanced(s);
    EXPECT_EQ(answer, no);
}
TEST(BalancedBrackets, yes1){
    string answer = isBalanced("[](){()}");
    EXPECT_EQ(answer, yes);
}
TEST(BalancedBrackets, yes2){
    string answer = isBalanced("()");
    EXPECT_EQ(answer, yes);
}
TEST(BalancedBrackets, yes3){
    string answer = isBalanced("({}([][]))[]()");
    EXPECT_EQ(answer, yes);
}
TEST(BalancedBrackets, no2){
    string answer = isBalanced("{)[](}]}]}))}(())(");
    EXPECT_EQ(answer, no);
}
TEST(BalancedBrackets, no3){
    string answer = isBalanced("([[)");
    EXPECT_EQ(answer, no);
}
TEST(BalancedBrackets, whatever) {
    string answer = isBalanced("");
}

int main(int argc, char **argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}