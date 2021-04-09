#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

enum Month {
    _NULL, JANUARY, FEBRUARY, MARCH, APRIL, MAY, JUNE, JULY, AUGUST, SEPTEMBER, OCTOBER, NOVEMBER, DECEMBER
};

struct Date {
    unsigned short int day     = 1;           // Not sure to use unsigned int or unsigned char.
    Month month                = JANUARY;     // Char makes sense but when printing you need to cast to int
    unsigned short int year    = 1970;
};


Month next(Month m) {
    if(((unsigned short int)m + 1) <= 13)
        return (m == DECEMBER) ? JANUARY : (Month)((unsigned short int)m + 1);
    return _NULL;
}

Month previous(Month m) {
    if(((unsigned short int)m - 1) > 0)
        return (Month)((unsigned short int)m - 1);
    return _NULL;
}

unsigned short to_int(Month m) {
    if((unsigned short int) m > 0 && (unsigned short int) m <= 12) return (unsigned short int)m;
    else                                                           return 0;
}

char* to_str(Month m) { // todo casteado a char* porque el compilador lo toma como warning
    char* strs[] = {(char*)"NULL", (char*)"JANUARY", (char*)"FEBRUARY", (char*)"MARCH",
                    (char*)"APRIL", (char*)"MAY", (char*)"JUNE", (char*)"JULY", (char*)"AUGUST",
                    (char*)"SEPTEMBER", (char*)"OCTOBER", (char*)"NOVEMBER", (char*)"DECEMBER"};
    if((unsigned int) m > 0 && (unsigned short int) m <= 12) return strs[(unsigned short int)m];
    else                                                     return strs[0];
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
// Como en ascii el '0' es el 48, le podemos restar directamente '0' para convertirlo a int.
Date to_date(char *str) {       // se puede hacer muchísimo más fácil esta función con la librería string,
    if(str == nullptr)             // pero tuve en cuenta que en este tp todavia "no sabemos" usarla.
        return {0, _NULL, 0};
    unsigned char day, month;
    char year[5];

    for(unsigned short int i = 0; i <= 9; i++) {
        if(i == 0 || i == 1) {                  // days position
            if(i == 0) day = (str[i] - '0') * 10;
            else       day += (str[i] - '0');
        } else if(i == 3 || i == 4) {           // month position
            if(i == 3) month = (str[i] - '0') * 10;
            else       month += (str[i] - '0');
        } else if(i >= 6) {                     // year position
            year[i - 6] = str[i];
        }
    }
    unsigned short int y = 0, k = 3;
    for(char n: year) {
        n -= '0';
        if((n) >= 0 && (n) <= 9) {
            y += (unsigned short int)((unsigned short int)(n) * pow(10, k));
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
            if(date.month == JANUARY || date.month == MARCH   || date.month == MAY ||
               date.month == AUGUST  || date.month == OCTOBER || date.month == DECEMBER)
                    return date.day <= 31 && date.day >= 1;
            else if(date.month == FEBRUARY) {
                return (leapYear(date) && (date.day <= 29 && date.day >= 1)) ||
                       (!leapYear(date) && (date.day <= 28 && date.day >= 1));
            } else
                return (date.day <= 30 && date.day >= 1);
        }
    }
    return false;
}


/**
* @brief Convierte un Date en una cadena con el formato dd/mm/yyyy
* @param d
* @return char *
*/
char* to_str(Date d) {      // se puede hacer muchísimo más fácil esta función con la librería string,
                            // pero tuve en cuenta que en este tp todavia "no sabemos" usarla.
    char* str = new char[9];
    if(!isValidDate(d))
        return str;

    for(unsigned short int i = 0; i <= 9; i++) {
        if(i == 2 || i == 5)
            str[i] = '/';
        else {
            if(i == 0 || i == 1) {                                      // days position
                if(d.day < 10)                                          // if the day has only one character
                    str[i] = (i == 0) ? '0' : '0' + d.day;
                else
                    str[i] = (i == 0) ? '0' + (d.day / 10) : '0' + (d.day % 10);
            } else if(i == 3 || i == 4) {                               // month pos
                if(to_int(d.month) < 10)                                // if the month has only one character
                    str[i] = (i == 3) ? '0' : '0' + to_int(d.month);
                else
                    str[i] = (i == 3) ? '0' + (d.month / 10) : '0' + (d.month % 10);
            } else if(i >= 6) {                                         // year pos
                str[i] = '0' + (d.year / (unsigned short int)pow(10, (3 - (i - 6))) % 10);
            }
        }
    }
    return str;
}

unsigned int dayOfYear(Date d) {
    unsigned short int leapYearCal   [] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    unsigned short int nonLeapYearCal[] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
    return (leapYear(d)) ? leapYearCal[d.month - 1] + d.day : nonLeapYearCal[d.month - 1] + d.day;
}

int getDifference(Date dt1, Date dt2) {
    short int diff = 0;
    if(isValidDate(dt1) && isValidDate(dt2)) {
        if(dt1.month == dt2.month && dt1.year == dt2.year)
            return dt2.day - dt1.day;

        Date MinYear = (dt1.year > dt2.year) ? dt2 : dt1,
             MaxYear = (dt1.year < dt2.year) ? dt2 : dt1;

        for(unsigned short int i = (MinYear.year + 1); i <= MaxYear.year; i++) {
            diff += (leapYear({1, JANUARY, i})) ? 366 : 365;
        }

        auto d = (short int)(dayOfYear(dt1) - dayOfYear(dt2));
        return (diff += d) * ((d < 0 || dt1.year > dt2.year) ? -1 : 1);
    }
    return 0;
}

enum Orden {
    asc  = 0,
    desc = 1
};

typedef bool orden;

void sort(Date *dates, size_t N, orden o=asc) {
    for(unsigned short int i = 0; i <= (unsigned short int)N; i++) {
        for(unsigned short int j = 0; j < (unsigned short int)(N - 1); j++) {
            if(getDifference(dates[j], dates[j + 1]) > 0) {
                Date tmp     = dates[j];
                dates[j]     = dates[j + 1];
                dates[j + 1] = tmp;
            }
        }
    }
    if(o == asc) {
        unsigned short int j =  N - 1;
        for(unsigned short int i = 0; i < j; i++, j--) {
            Date tmp = dates[i];
            dates[i] = dates[j];
            dates[j] = tmp;
        }
    }
}

#endif // DATE_H_INCLUDED
