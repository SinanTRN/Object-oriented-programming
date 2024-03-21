#include <iostream>
#include <queue>
#include <stack>
#include <deque>

using namespace std;
bool is_palindrome1(string ifade) {
    deque<char> gecici;
    
    for (char chr : ifade) {
        
        if (isalpha(chr)) {
           
            gecici.push_back(toupper(chr));

        }
    }

    while (1 <gecici.size()) {
        
        if (gecici.front() != gecici.back()) {
            
            return false;

        }
        
        gecici.pop_front();
        gecici.pop_back();
    }

    return true;
}
bool is_palindrome2(string ifade) {
    stack<char> yigin;
    queue<char> kuyruk;
    
    for (char chr : ifade) {
        
        if (isalpha(chr)) {
        
            yigin.push(toupper(chr));
            kuyruk.push(toupper(chr));

        }

    }

    while (1 < kuyruk.size()) {
        
        if ( yigin.top() != kuyruk.front()  ) {
        
            return false;

        }

        yigin.pop();
        kuyruk.pop();

    }

    return true;
}

