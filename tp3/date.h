/*************************
    Trabajo Práctico 3
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iomanip>
#include <ctime>
#include <cstdlib>

/**
 *
 * Al utilizar objetos, nos permite organizar mejor la información y usar las clases de una manera más
 * amigable al programador. Otra ventaja es que se pueden definir datos privados (encapsulación).
 *
 */


/**
 * Class to manage dates.
 * @class Date
 */
class Date {
public:
    /**
     * Constructors
     * Default: local time
     * Parameterized: gets an string with a date and scrapes it to store the date. ("00/00/0000")
     */
    Date() {
        time_t curr_time = time(nullptr);
        tm *tm_local = localtime(&curr_time);

        day   = tm_local->tm_mday;
        month = tm_local->tm_mon + 1;
        year  = tm_local->tm_year + 1900;
    }
    explicit Date(const std::string& str) {
        this->day   = std::atoi(str.substr(0,2).c_str());
        this->month = std::atoi(str.substr(3,4).c_str());
        this->year  = std::atoi(str.substr(6,9).c_str());
        if(!isValidDate(day, month, year) || !(str[2] == '/' && str[5] == '/')) {
            new (this) Date();
        }
    }

    /**
     * Minor operator.
     * @param d
     * @return bool
     */
    bool operator < (Date &d) {
        return ((month * 100 + year * 1000 + day * 10) < (d.month * 100 + d.year * 1000 + d.day * 10));
    }
    /**
     * Max operator.
     * @param d
     * @return bool
     */
    bool operator > (Date &d) { return !(*this < d); }
    /**
     * Minor equal operator.
     * @param d
     * @return bool
     */
    bool operator <= (Date &d) { return *this < d || *this == d; }
    /**
     * Max equal operator.
     * @param d
     * @return bool
     */
    bool operator >= (Date &d) { return *this > d || *this == d; }
    /**
     * Equals operator.
     * @param d
     * @return bool
     */
    bool operator == (const Date &d) {
        return day == d.day && month == d.month && year == d.year;
    }
    /**
     * Not equals operator.
     * @param d
     * @return bool
     */
    bool operator != (const Date &d) { return !(*this == d); }
    /**
     * Prints to console formatted ( 00/00/0000 )
     * @param out
     * @param d
     * @return out
     */
    friend std::ostream &operator << (std::ostream &out, Date d) {
        return out << d.day << "/" << d.month << "/" << d.year << std::endl;
    }
    /**
     * Input stream.
     * @param in
     * @param d
     * @return in
     */
    friend std::istream& operator >>(std::istream &in, Date &rhs) {
        unsigned short int d, m, y;
        in >> d >> m >> y;
        if(isValidDate(d, m, y)) {
            rhs.day   = d;
            rhs.month = m;
            rhs.year  = y;
        }
        return in;
    }
    /**
     * Sets the day and checks if the day is valid.
     * @param day
     */
    void setDay(int newDay) {
        if(isValidDate(newDay, this->month, this->year)) { this->day = newDay; }
    }
    /**
     * Sets the month and checks if it's >= 1 && <= 12.
     * @param month
     */
    void setMonth(int newMonth) {
        if (newMonth >= 1 && newMonth <= 12) this->month = newMonth;
    }
    /**
     * Sets the year and checks if it's >= 1 && <= 9999.
     * @param year
     */
    void setYear(int newYear) {
        if(newYear >= 1 && newYear <= 9999 ) this->year = newYear;
    }

    /**
     * Gets the day.
     * @return day
     */
    int getDay() { return this->day; }
    /**
     * Gets the month.
     * @return month
     */
    int getMonth() { return this->month; }
    /**
     * Gets the year.
     * @return year
     */
    int getYear() { return this->year; }

private:
    unsigned int day, month, year;

    enum Month {
        JANUARY, FEBRUARY, MARCH, MAY, AUGUST, OCTOBER, DECEMBER
    };
    /**
     * Returns if a year is a leap year.
     * @param year
     * @return bool
     */
    static bool leapYear(int year) {
        return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
    }
    /**
     * Returns if a date is valid or not.
     * @param day
     * @param month
     * @param year
     * @return bool
     */
    static bool isValidDate(int day, int month, int year) {
        if(year >= 1 && year <= 9999) {
            if(month <= 12 && month >= 1) {
                if(month == JANUARY || month == MARCH   || month == MAY ||
                   month == AUGUST  || month == OCTOBER || month == DECEMBER)
                    return day <= 31 && day >= 1;
                else if(month == FEBRUARY) {
                    return (leapYear(year) && (day <= 29 && day >= 1)) ||
                           (!leapYear(year) && (day <= 28 && day >= 1));
                } else return (day <= 30 && day >= 1);
            }
        }
        return false;
    }
};

#endif // DATE_H_INCLUDED
