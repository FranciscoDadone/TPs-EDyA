#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

class Counter {
public:
    Counter(){
        count=0;
    }
    Counter(const Counter &c){
        this->count = c.count;
    }
    Counter(const unsigned int &c){
        this->count = c;
    }
    Counter operator=(int i){// "asigna un entero al Counter"
        Counter rta;
        rta.count = this-> count = i;
        return rta;
    }
    Counter operator=(const Counter &c){
        Counter rta;
        rta.count = this-> count = c.count;
        return rta;
    }
    friend std::ostream& operator <<(std::ostream& out, Counter c){
        return out << c.count << std::endl;
    }
    Counter operator++(){// "Pre-increment Operator"
        Counter rta;
        rta.count = this-> count=++count;
        return rta;
    }
    Counter operator++(int){// "Post-increment Operator"
        Counter rta;
        rta.count = this-> count++;
        return rta;
    }
    Counter& operator+=(int i){
        Counter rta;
        rta.count = this-> count=count+i;
        return rta;
    }
private:
    unsigned int count;
};

#endif
