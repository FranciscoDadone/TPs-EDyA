// El trabajo no está del todo completo, lo entrego hoy mismo a la noche porque viajo mañana a la mañana y no tengo posibilidad de seguirlo haciendo.
// Hice las funciones y en el main están las llamadas a las mismas comentadas para probar una por una.

#include <iostream>
using namespace std;


size_t edya_strlen(char * str) {
    int i = 0;
    while(str[i] != '\0') {
        i++;
    }
    return i;
}

char * edya_strcat(char * str1, char * str2) {
    size_t len = edya_strlen(str1) + edya_strlen(str2);
    char* str = new char[len];

    for(int i = 0; i < edya_strlen(str1); i++) {
        str[i] = str1[i];
    }
    for(int i = edya_strlen(str1); i < len; i++) {
        str[i] = str2[i - edya_strlen(str1)];
    }
    return str;
}


struct Date {
    int day;
    int month;
    int year;
};

bool leapYear(unsigned int y) {
    if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0) //Condición de bisiesto
      return true;
    else
      return false;
}

bool leapYear(Date d) {
    if(d.year % 4 == 0 && d.year % 100 != 0 || d.year % 400 == 0) //Condición de bisiesto
      return true;
    else
      return false;
}

int datecmp(Date d1, Date d2) {
    if(d1.year > d2.year) {
        return 1;
    } else if(d1.year < d2.year) {
        return -1;
    } else {
        if(d1.month > d2.month) {
            return 1;
        } else if(d1.month < d2.month) {
            return -1;
        } else {
            if(d1.day > d2.day) {
                return 1;
            } else if(d1.day < d2.day) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

unsigned int dayOfYear(Date d) {
    int leapYearCal[] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    int nonLeapYearCal[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    if(leapYear(d)) {
        return leapYearCal[d.month - 1] + d.day;
    } else {
        return nonLeapYearCal[d.month - 1] + d.day;
    }
}

void printBidimentionalMatrix() {
    int ROWS = 3, COLS = 4;
    int num[ROWS][COLS] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 11, 12}
    };
    // pointer
    int *ptr = &num[0][0];
    // print
    for(int i = 0; i < ROWS * COLS; i++)
    {
        int r = i / COLS;
        int c = i % COLS;
        cout << num[r][c] << endl;
    }
}


int main() {

// EJ 1
    // cout << edya_strlen("abc") << endl;
    // cout << edya_strcat("ab", "cd") << endl;

// EJ 2
    Date d = {10, 3, 1988};
    // cout << leapYear(1988) << endl;
    // cout << leapYear(d) << endl;
    Date d1 = {10, 1, 1988};
    Date d2 = {10, 1, 1981};
    // cout << datecmp(d1,d2) << endl;
    // cout << dayOfYear(d) << endl;

// EJ 5
    // printBidimentionalMatrix();
    return 0;
}

// EJ 3
void test_pointer() {
    char a = 'a';
    char * b;
    int * c[9];
    int **d;
    int e[4][3];
    int * f[4][3]; 
    Date * g[1];
}