#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> checker;

        // If string empty return true
        if (s.size() == 0) { return true; }

        // Start filling the stack
        for(size_t i = 0; i < s.size(); i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                checker.push(s[i]);
            } 
            else if(checker.empty()) {
                return false;
            } else {
                if(s[i] == ')') {
                    if (checker.top() == '(') {
                        checker.pop();
                    }
                    else {
                        return false;
                    }
                }   

                if(s[i] == ']') {
                    if(checker.top() == '[') {
                        checker.pop();
                    }
                    else {
                        return false;
                    }
                }

                if(s[i] == '}') {
                    if(checker.top() == '{') {
                        checker.pop();
                    } 
                    else {
                        return false;
                    }
                }
            }
        }
        return checker.empty();
    }
};