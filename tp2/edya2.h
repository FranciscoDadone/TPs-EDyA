#ifndef EDYA2_H_INCLUDED
#define EDYA2_H_INCLUDED

#include <stack>

using namespace std;

bool palindrome(const string& str) {
    stack <char> s;

    for(char c: str) s.push(c);

    unsigned short int i = 0;
    while(!s.empty()) {
        if(s.top() != str[i]) return false;
        s.pop();
        i++;
    }
    return true;
}



#endif // EDYA2_H_INCLUDED
