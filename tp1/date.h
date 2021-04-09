#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <math.h>

enum Month {
    _NULL, JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

struct Date {
    unsigned int day     = 1;           // Not sure to use unsigned int or unsigned char.
    Month month          = JANUARY;     // Char makes sense but when printing you need to cast to int
    unsigned int year    = 1970;
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
    if(m >= 1 && m <= 12)
        return (Month)m;
    return (Month)NULL;
}

/**
* @brief Devuelve una fecha a partir de una cadena de caracteres
* de formato dd/mm/yyyy
* @return Date
*/
Date to_date(char *str) {
    if(str == NULL)
        return {0, _NULL, 0};
    unsigned char day, month, j = 0;
    char year[5];

    for(unsigned int i = 0; i <= 9; i++) {
        if(i == 0 || i == 1) { // days pos
            day += (str[i] - '0');
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
    unsigned int y = 0, k = 3;
    for(char n: year) {
        if((n - '0') >= 0 && (n - '0') <= 9) {
            y += (unsigned int)(n - '0') * pow(10, k);
            k--;
        }
    }
    return {day, to_month(month), y};
}

/**
* @brief Retorna si es año bisiesto
* @param d
*/
bool leapYear(Date d) {
    return ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0));
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
                if(leapYear(date) && (date.day <= 29 && date.day >= 1)) return true;
                else if(!leapYear(date) && (date.day <= 28 && date.day >= 1)) return true;
                break;
            case APRIL    :
            case JUNE     :
            case JULY     :
            case SEPTEMBER:
            case NOVEMBER :
                if(date.day <= 30 && date.day >= 1) return true;
                break;
            case _NULL: return false;
            }
        }
    }
    return false;
}


/**
* @brief Convierte un Date en una cadena con el formato dd/mm/yyyy
* @param d
* @return char *
*/
char* to_str(Date d) {
    char* str = (char*)malloc(10);
    if(!isValidDate(d))
        return str;

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
    return 0;
}

enum {
    asc  = 0,
    desc = 1
};

typedef bool orden;

void sort(Date *dates, size_t N, orden o=asc) {
    for(unsigned int i = 0; i <= (unsigned int)N; i++) {
        for(unsigned int j = 0; j < (unsigned int)(N - 1); j++) {
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
