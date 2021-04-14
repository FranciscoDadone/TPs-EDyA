#include <iostream>
#include <string>
#include "edya2.h"


using namespace std;

int main()
{
    //cout << palindrome("reconocer") << endl;

    /*
    vector<unsigned int> v = create(10, 3, 20);
    for(unsigned int i: v) {
        cout << i << endl;
    }
    */

    vector<unsigned int> v = {11, 40, 41, 13, 55, 90, 1, 3};
    //print(v, FMT_LINE);
    //sort(v); print(v);

    vector<unsigned int> v1 = {1, 2, 3, 4};
    vector<unsigned int> v2 = {6, 7, 8};

    vector<unsigned int> v3 = insert(v1,v2,1);
    print(v3);

    return 0;
}
