/*************************
    Trabajo Práctico 3
    Grupo: 9

    Julian Cordoba
    Valentín Fernandez
    Francisco Dadone
*************************/

#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

/**
 * Class Counter
 * Counts from a value passed from parameter.
 */
class Counter {
public:
    /**
     * Constructors
     *  - Default: count = 0
     *  - Copy: copies a counter from another
     *  - Parameterized: takes an int and stores it in count.
     */
    Counter(const Counter &c) { this -> count = c.count; }
    Counter(const unsigned int &c = 0) { this -> count = c; }

    // Operators
    /**
     * Assigns an int to count.
     * @param i
     * @return returns another object with the updated count.
     */
    Counter operator=(int i) { return this -> count = i; }
    /**
     * Assigns c.count to count.
     * @param c
     * @return returns another object with the updated count.
     */
    Counter operator=(const Counter &c) { return this -> count = c.count; }
    /**
     * Outputs to terminal the count.
     * @param out
     * @param c
     * @return
     */
    friend std::ostream& operator << (std::ostream& out, Counter c) {
        return out << c.count << std::endl;
    }
    /**
     * Pre-increment operator
     * @return
     */
    Counter operator++() {
        return this -> count = ++count;
    }
    /**
     * Post-increment operator.
     * @return
     */
    Counter operator++(int) {
        return this -> count++;
    }
    /**
     * Plus equal operator.
     * @param i
     * @return
     */
    Counter& operator+=(int i) {
        this -> count += i;
        return *this;
    }

private:
    unsigned int count;
};

#endif
