#include <iostream>
#include "counter.h"
#include <iomanip>
#include <ctime>
#include "date.h"
#include <cstdlib>

using namespace std;

int main()
{
   string s;
   Date d(s);
   cout<<d<< endl;

}
/*
int main()
{/*
    Counter c, c3;
    cout << "C " << c << endl;
    Counter c1(c);
	cout<<"C1 "<< c1<< endl;
	Counter c2(88);
    cout<<"C2 "<< c2<< endl;
    c3=9;
    c2=c3;
    ++c2;
    c1++;
    cout<<"C3 "<< c3<<c2<<c1<<endl;
    c3+=5;
    cout<<"C3 "<< c3;
    return 0;
    */

