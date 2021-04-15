#include <iostream>
#include <queue>
#include <stack>

std::queue<int>& reverse(std::queue <int> &myqueue){
   std:: stack <int> s;
    while (!myqueue.empty()) {
        s.push (myqueue.front());
        myqueue.pop();
    }
    while (!s.empty()) {
        myqueue.push (s.top());
        s.pop();
    }
    return myqueue;
}
