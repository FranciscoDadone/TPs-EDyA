#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iomanip>
#include <ctime>
#include <cstdlib>

class Date {
public:
    Date(){
       day=0;     //auto t = std::time(nullptr);
        month=0;
       year=0;          //auto tm = *std::localtime(&t);
                        //std::cout << std::put_time(&tm, "%d-%m-%Y %H-%M-%S") << std::endl;

    }
    Date(const std::string &str){
        this->day = std::atoi(str.c_str());


    }
        bool operator<(Date & d){
            if(this(day*month*year)<(day*month*year)){return ((this(day*month*year)<}};
        bool operator>(const Date & d){return (*this > h);}
        bool operator<=(const Date & d){return (*this < h||*this==h);}
        bool operator>=(const Date & d){return (*this > h||*this==h);}
        bool operator==(const Date & d){
            return (day == d.day && month == d.month && year == d.year);
        }
        bool operator!=(const Date & d){return !(*this == d);
        }

    friend std::ostream& operator <<(std::ostream& out, Date d){
        return out <<("d.day","d.month","d.year")<< std::endl;
    }
    friend std::istream& operator <<(std::istream& in, Date d){
        return in <<("d.day","d.month","d.year")<< std::endl;
    }
    void setday(int day){
        (if day<1 && day<31){this->day=day;}}
    void setmonth(int month){
        (if month<1 && month<12){this->month=month;}
    void setyear(int year){{this->year=year;}

    int getday(){return this->day;}
    int getmonth(){return this->month;}
    int getyear(){return this->year;}

private:
    unsigned int day, month, year;
};

#endif // DATE_H_INCLUDED
