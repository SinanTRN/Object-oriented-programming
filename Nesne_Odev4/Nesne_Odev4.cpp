#include <iostream>
#include <deque>
#include <stack>
#include <queue>
using namespace std;
bool is_palindrome1(const string& kelime) {
    deque<char> result;
    bool control = true;
    for (char ifade : kelime) {
        if (isalpha(ifade))
        result.push_back(toupper(ifade));
        
    }
    while (result.size() > 1) {
        if (result.front() != result.back())
            control = false;
       

        result.pop_front();
        result.pop_back();
    }

    return control;
}
bool is_palindrome2(const string& kelime) {
    queue<char> result;
    stack<char> result2;

    bool control = true;
    for (char ifade : kelime) {
        if (isalpha(ifade)) {
            result.push(toupper(ifade));
            result2.push(toupper(ifade));
        }
    }

    while (result.size() > 1) {
        if (result.front() != result2.top())
            control = false;
        
        result.pop();
        result2.pop();
    }
    return control;
}

