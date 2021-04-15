#include <iostream>
#include <queue>

using namespace std;

void print(std::queue<int> &myqueue);
std::queue<int>& reverse(std::queue<int> &myqueue);

int main()
{
    std::queue<int> myqueue ;
    myqueue.push(5);
    myqueue.push(3);
    myqueue.push(1);
    print(myqueue);
    cout<<'\n';
    print(reverse(myqueue));
    return 0;
}
