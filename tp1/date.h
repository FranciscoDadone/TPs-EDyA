#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <math.h>

enum Month {
    _NULL     = 0,
    JANUARY   = 1,
    FEBRUARY  = 2,
    MARCH     = 3,
    APRIL     = 4,
    MAY       = 5,
    JUNE      = 6,
    JULY      = 7,
    AUGUST    = 8,
    SEPTEMBER = 9,
    OCTOBER   = 10,
    NOVEMBER  = 11,
    DECEMBER  = 12
};

struct Date {
    int day     = 1;
    Month month = JANUARY;
    int year    = 1970;
};


Month next(Month m) {
    if(((unsigned int)m + 1) <= 12) {
        return (Month)((int)m + 1);
    }
    return m;
}

Month previous(Month m) {
    if(((unsigned int)m - 1) > 0) {
        return (Month)((unsigned int)m - 1);
    }
    return m;
}

unsigned short to_int(Month m) {
    return (unsigned int)m;
}

char* to_str(Month m) {
    char* toReturn = NULL;
    switch(m) {
    case JANUARY:
        toReturn = (char*)"JANUARY"; break;
    case FEBRUARY:
        toReturn = (char*)"FEBRUARY"; break;
    case MARCH:
        toReturn = (char*)"MARCH"; break;
    case APRIL:
        toReturn = (char*)"APRIL"; break;
    case MAY:
        toReturn = (char*)"MAY"; break;
    case JUNE:
        toReturn = (char*)"JUNE"; break;
    case JULY:
        toReturn = (char*)"JULY"; break;
    case AUGUST:
        toReturn = (char*)"AUGUST"; break;
    case SEPTEMBER:
        toReturn = (char*)"SEPTEMBER"; break;
    case OCTOBER:
        toReturn = (char*)"OCTOBER"; break;
    case NOVEMBER:
        toReturn = (char*)"NOVEMBER"; break;
    case DECEMBER:
        toReturn = (char*)"DECEMBER"; break;
    default: break;
    }
    return toReturn;
}

Month to_month(unsigned short m) {
    if(m >= 1 && m <= 12) {
        return (Month)m;
    }
    return (Month)NULL;
}

/**
* @brief Convierte un Date en una cadena con el formato dd/mm/yyyy
* @param d
* @return char *
*/
char* to_str(Date d) {

    char* str = (char*)malloc(10);

    for(unsigned int i = 0; i <= 9; i++) {
        if(i == 2 || i == 5) {
            str[i] = '/';
        } else {
            if(i == 0 || i == 1) {  // days position
                if(d.day < 10) {    // if the day has only one character
                    if(i == 0) {
                        str[i] = '0';
                    } else if(i == 1) {
                        str[i] = '0' + d.day;
                    }
                } else {
                    if(i == 0) {
                        str[i] = '0' + (d.day / 10);
                    } else {
                        str[i] = '0' + (d.day % 10);
                    }
                }
            } else if(i == 3 || i == 4) { // month pos
               if(to_int(d.month) < 10) {    // if the month has only one character
                    if(i == 3) {
                        str[i] = '0';
                    } else {
                        str[i] = '0' + to_int(d.month);
                    }
                } else {
                    if(i == 3) {
                        str[i] = '0' + (d.month / 10);
                    } else {
                        str[i] = '0' + (d.month % 10);
                    }
                }
            } else if(i >= 6) { // year pos
                if(i == 6) {
                    str[i] = '0' + (int)(d.year / 1000);
                } else if(i == 7) {
                    str[i] = '0' + (int)((d.year / 100) % 10);
                } else if(i == 8) {
                    str[i] = '0' + (int)((d.year / 10) % 10);
                } else if(i == 9) {
                    str[i] = '0' + (int)(d.year % 10);
                }
            }
        }
    }
    return str;
}

/**
* @brief Devuelve una fecha a partir de una cadena de caracteres
* de formato dd/mm/yyyy
* @return Date
*/
Date to_date(char *str) {
    if(str == NULL)
        return (Date){NULL, _NULL, NULL};
    unsigned int day, month, j = 0;
    char year[5];

    for(unsigned int i = 0; i <= 9; i++) {
        if(i == 0 || i == 1) { // days pos
            if(i == 0) {
                day = (str[i] - '0') * 10;
            } else {
                day += (str[i] - '0');
            }
        } else if(i == 3 || i == 4) { // month pos
            if(i == 3) {
                month = (str[i] - '0') * 10;
            } else {
                month += (str[i] - '0');
            }
        } else if(i >= 6) {
            year[j] = str[i];
            j++;
        }
    }
    int y = 0, k = 3;
    for(char n: year) {
        if((n - '0') >= 0 && (n - '0') <= 9) {
            y += (unsigned int)(n - '0') * pow(10, k);
            k--;
        }
    }
    return (Date){day, to_month(month), y};
}

/**
* @brief Retorna si es año bisiesto
* @param d
*/
bool leapYear(Date d) {
    return (d.year % 4 == 0 && d.year % 100 != 0 || d.year % 400 == 0);
}

/**
* @brief Retorna true si una fecha es correcta
* @return bool
*/
bool isValidDate(Date date) {
    if(date.year >= 1 && date.year <= 9999) {
        if(date.month <= 12 && date.month >= 1) {
            switch(date.month) {
            case JANUARY :
            case MARCH   :
            case MAY     :
            case AUGUST  :
            case OCTOBER :
            case DECEMBER:
                if(date.day <= 31 && date.day >= 1) {return true;} break;
            case FEBRUARY:
                if(leapYear(date) && (date.day <= 29 && date.day >= 1)) {return true;}
                else if(!leapYear(date) && (date.day <= 28 && date.day >= 1)) {return true;} break;
            case APRIL    :
            case JUNE     :
            case JULY     :
            case SEPTEMBER:
            case NOVEMBER :
                if(date.day <= 30 && date.day >= 1) {return true;} break;
            }
        }
    }
    return false;
}

unsigned int dayOfYear(Date d) {
    unsigned int leapYearCal   [] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    unsigned int nonLeapYearCal[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    if(leapYear(d)) {
        return leapYearCal[d.month - 1] + d.day;
    } else {
        return nonLeapYearCal[d.month - 1] + d.day;
    }
}


int getDifference(Date dt1, Date dt2) {

    // diferencia entre las fechas multiplicando por 1k los años, 100 los meses, 10 los años y restando las 2.

    int  diff   = 0;
    char symbol = 1;
    Date MinYear, MaxYear, MinMonth, MaxMonth, MinDay, MaxDay;
    if(isValidDate(dt1) && isValidDate(dt2)) {
        if(dt1.month == dt2.month && dt1.year == dt2.year){
            return dt2.day - dt1.day;
        }

        if(dt1.year > dt2.year) {
            MinYear = dt2;
            MaxYear = dt1;
        } else if(dt1.year < dt2.year) {
            MinYear = dt1;
            MaxYear = dt2;
        }

        for(unsigned int i = MinYear.year + 1; i <= MaxYear.year; i++) {
            Date leapYearCheckDate = {1, JANUARY, i};
            if(leapYear(leapYearCheckDate)) {
                diff += 366;
            } else {
                diff += 365;
            }
        }
        int d = dayOfYear(dt1) - dayOfYear(dt2);
        diff += d;
        if(d < 0 || dt1.year > dt2.year){
            d *= -1;
            symbol = -1;
        }
        return diff * symbol;
    }
}

enum {
    asc  = 0,
    desc = 1
};

typedef bool orden;

void sort(Date *dates, size_t N, orden o=asc) {
    for(int i = 0; i <= N; i++) {
        for(int j = 0; j < (N - 1); j++) {
            if((getDifference(dates[j], dates[j + 1]) > 0) && o == desc) {
                Date tmp     = dates[j];
                dates[j]     = dates[j + 1];
                dates[j + 1] = tmp;
            } else if(getDifference(dates[j + 1], dates[j]) > 0 && o == asc) {
                Date tmp     = dates[j];
                dates[j]     = dates[j + 1];
                dates[j + 1] = tmp;
            }
        }
    }
}


#endif // DATE_H_INCLUDED
